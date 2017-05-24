#include <lib.h>
inherit LIB_ROOM;

int doorcounter,callfloor,closed,floor,my_counter,moving;
string floorname;
static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Церковный лифт");
    SetLong("Вы находитесь в лифте деревенской церкви. Его дверь находится в западной стене. Рядом с дверью вы видите две кнопки, помеченные буквами '1' и 'b'.");
    floor=1;
    moving = 0;
    closed=1;
    callfloor=0;
    SetExits( ([
                "east" : "/domains/town/room/church",
                ]) );
    SetItems(([
                //new("/domains/town/obj/ebutton1") : 1,
                //new("/domains/town/obj/ebutton2") : 1,
                "лифт" : "Он может перемещаться вверх и вниз.",
                "стена" : "В стене вы видите две кнопки.",
                ({"дверь лифта","дверь"}) : "Через нее можно выйти наружу."
                ]) );
    AddItem(new("/domains/town/obj/ebutton2"));
    AddItem(new("/domains/town/obj/ebutton1"));
    set_heart_beat(1);
}
void init(){
    ::init();
    set_heart_beat(1);
}
int CallMe(int i){
    if(i == floor && moving == 0) {
        this_object()->SetDoorClosed(0);
        return 1;
    }
    else callfloor = i;
    return 1;
}
int SetDoorClosed(int i){
    if(i && i == closed) return i;
    if(!i && closed == 0) return i;
    if(i == 0 && closed == 0) return i;
    if(i) closed = i;
    else if( closed == 1 ) closed = 0;
    else if( closed == 0 ) closed =1;
    if(floor == 1) floorname = "/domains/town/room/church";
    if(floor == 2) floorname = "/domains/town/room/basement";
    if(closed < 1){
        tell_room(this_object(),"Двери лифта открылись.");
        tell_room(load_object(floorname),"Двери лифта открылись.");
        doorcounter = 10;
    }
    if(closed > 0) {
        tell_room(this_object(),"Двери лифта закрылись.");
        tell_room(load_object(floorname),"Двери лифта закрылись.");
        doorcounter = 0;
    }
    return closed;
}
int SetFloor(int i){
    if(floor == i) return 0;
    RemoveExit("east");
    floor = i;
    if(i == 1) AddExit("east", "/domains/town/room/church");
    if(i == 2) AddExit("east", "/domains/town/room/basement");
    return 1;
}
int CanReceive(object ob) {
#if 1
    if(living(ob) && closed > 0 && query_verb() != "goto" &&
            query_verb() != "trans"  ){
        message("info","Двери лифта закрыты.", ob);
        return 0;
    }
#endif
    return 1;
}
int CanRelease(object ob){
    if(archp(ob)) {
        tell_object(ob,"%^RED%^Как администратору, вам разрешено "
                "выходить из лифта в любое время. Обычные билдеры и "
                "игроки не могут сделать это.%^RESET%^\n");
    }
    if(closed > 0 && query_verb() == "go" ){
        message("info","Двери лифта закрыты.", ob);
        return 0;
    }
    return 1;
}
varargs int eventRoll(int i){
    if(!i) i = 10;
    moving = 1;
    SetDoorClosed(1);
    my_counter = i;
    return i;
}
void heart_beat(){
    if(doorcounter > 0){
        doorcounter--;
        if(doorcounter  < 2) SetDoorClosed(1);
    }

    if(moving == 0 && closed == 1 && callfloor > 0){
        tell_room(this_object(),"Лифт пришел в движение.");
        eventRoll();
    }

    if(moving && moving > 0){
        my_counter--;
        if(my_counter % 5  == 0) {
            tell_room(this_object(),"Лифт движется...");
        }

        if(my_counter < 2) {
            my_counter = 0;
            moving = 0;
            SetFloor(callfloor);
            tell_room(this_object(),"Лифт прибыл в место назначения.");
            SetDoorClosed(0);
            callfloor = 0;
        }
    }
}
