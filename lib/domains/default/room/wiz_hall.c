#include <lib.h>
#include ROOMS_H

inherit LIB_ROOM;
int ds;

string LongDesc(){
    string desc = "Бессмертные приходят сюда чтобы обсуждать "+
        "мир, который они создают. Начальная комната этого места "+
        "на севере, комната создателя на юге."+
        (!(ds) ? " Чтобы посетить "+
         "тестовые и служебные комнаты, подмитесь наверх." : "")+
        " А на востоке находятся тестовые лаборатории.";
    desc += "\nНа знаке написано: "+load_object(ROOM_ARCH)->SignRead();
    return desc;
}

static void create() {
    object ob;
    room::create();
    if(mud_name() == "Dead Souls"){
        ds = 1;
    }
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Зал билдеров");
    SetLong( (: LongDesc :) );
    SetProperty("no attack", 1);
    SetProperty("nopeer",1);
    ob = new("/lib/bboard");
    ob->SetKeyName("доска объявлений");
    ob->SetId( ({ "доска", "доска объявлений", "объявлений", "объявления" }) );
    ob->set_board_id("immortal_board");
    ob->set_max_posts(30);
    ob->SetShort("доска объявлений");
    ob->eventMove(this_object());
    SetInventory(([
                "/domains/default/npc/tree" : ({ 10, 1 }),
                "/domains/default/obj/chest" : 1 ]));
    SetItems( ([
                ({"знак"}) : "На знаке что-то написано.",
                ]) );
    SetExits( ([
                "south" : "/secure/room/arch",
                "north" : "/domains/default/room/start",
                "east" : "/domains/default/room/wiz_corr1",
                "up" : "/domains/default/room/wiz_hall2.c",
                "west" : "/domains/default/room/wiz_hall_prool.c",
                ]) );
    SetRead("знак", (: load_object(ROOM_ARCH)->SignRead() :) );
}

int CanReceive(object sneak) {
    object *living_stack = get_livings(sneak);
    if(!living_stack || !arrayp(living_stack)) living_stack = ({ sneak });
    foreach(object ob in living_stack){
        if(living(ob) && !creatorp(ob) && 
                base_name(ob) != "/domains/default/npc/tree" &&
                base_name(ob) != "/secure/npc/arch_wraith" &&
                base_name(ob) != "/domains/default/npc/drone3" &&
                base_name(ob) != "/secure/obj/floodmapper" &&
                !member_group(ob,"TEST")) {
            message("info","Извините, но эта вещь только для билдеров.", ob);
            return 0;
        }
    }
    return ::CanReceive(sneak);
}

int eventReceiveObject(object ob){
    string race = ob->GetRace();
    int ret = ::eventReceiveObject(ob);
    if(!ret) return 0;
    if(race && race == "orc"){
        ob->eventPrint("Добро пожаловать в наши скрытые помещения, славный орк!");
    }
    if(ob->GetInvis()){
        tell_room(this_object(), capitalize(ob->GetKeyName())+
                " стал невидимым.", ({ ob }) );
        ob->eventPrint("%^BOLD%^%^RED%^Ваш невидимый вход "+
                "был замечен.%^RESET%^");
    }
    return ret;
}

int eventReleaseObject(object ob){
    int ret = ::eventReleaseObject(ob);
    if(!ret) return 0;
    if(ob->GetInvis()){
        tell_room(this_object(), capitalize(ob->GetKeyName())+
                " стал невидимым.", ({ ob }) );
        ob->eventPrint("%^BOLD%^%^RED%^Ваш невидимый вход "+
                "стал замечен.%^RESET%^");
    }
    return ret;
}

void init(){
    ::init();
}
