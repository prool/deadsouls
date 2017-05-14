#include <lib.h>
#include ROOMS_H

inherit LIB_ROOM;

int privacy, timer;
string ExtraDesc();
static void create() {
    string privs;
    privs = query_privs();
    if( privs ) privs = capitalize(privs);
    else privs = "билдер";
    room::create();
    SetClimate("indoors");
    SetAmbientLight(40);
    SetShort("Приватная комната");
    SetLong((: ExtraDesc :));
    SetInventory(([
                "/domains/town/obj/chair" : 4,
                "/domains/town/obj/bbucket" : 1,
                "/secure/npc/cambot" : 1
                ]));
    SetExits(([
                "west" : "/domains/town/room/adv_guild",
                ]));

    SetProperties(([
                "no attack" : 1,
                "nopeer" : 1,
                "meeting room" : 1,
                ]));
    SetNoClean(1);
    privacy=0;
    set_heart_beat(20);
    timer = 0;

}

int AutoDeactivate(){
    message("info","%^RED%^Приватность нарушена!%^RESET%^", this_object());
    timer = 0;
    privacy = 0;
    return 1;
}

void init(){
    ::init();
    add_action("privacy","приватность");
    add_action("privacy","приват");
    add_action("report_time","таймер");
}

void heart_beat(){
    if(timer && (time() - timer ) > 1200) AutoDeactivate();
}

int report_time(){
    int secs = time() - timer;

    if(!timer){
        write("Приватность не активирована.");
        return 0;
    }

    write("Осталось секунд: "+secs);
    write("Осталось минут: "+(secs/60));
    return secs;
}

int CanReceive(object ob) {
    if(privacy){
        if(!interactive(ob)) { 
            message("info","\n\nПРЕДУПРЕЖДЕНИЕ: "+ob->GetName()+" вошел в комнату.\n\n",this_object() );
        }
        else if(!archp(ob)){
            message("info","Вас не пускает в приватную комнату.", ob);
            message("info",ob->GetName()+" не пускает в приватную комнату.",this_object());
            if(!environment(ob)) ob->eventMoveLiving(ROOM_START);
            return 0;
        }

    }
    return room::CanReceive();
}

int set_privacy(int i){
    if(environment(this_player()) != this_object() && !archp(this_player())) {
        write("У вас нет достаточных привилегий для этого.");
        say(this_player()->GetName()+" пытается войти в приватную комнату.");
        return 1;
    }
    privacy=i;
    return 1;
}

int privacy(string str){
    if(environment(this_player()) != this_object() && !archp(this_player())) {
        write("У вас нет достаточных привилегий для этого.");
        say(this_player()->GetName()+" пытается подслушать происходящее.");
        return 1;
    }

    if(str=="вкл" || str == "1"){
        this_object()->set_privacy(1);
        write("Вы активировали защиту от прослушивания.\n");
        say(this_player()->GetName()+" активировал защиту от прослушивания.");
        timer = time();
        return 1;
    }
    if(str=="выкл" || str == "0"){
        this_object()->set_privacy(0);
        write("Вы деактивировали защиту от прослушивания.\n");
        say(this_player()->GetName()+" деактивировал защиту от прослушивания.");
        timer = 0;
        return 1;
    }
}

string ExtraDesc(){
    string extra = "%^YELLOW%^Защита от прослушивания активна.%^RESET%^";
    string desc = "Эта комната зачарована так, что препятствует проникновению незванных людей. Она используется когда трем и более людям необходимо обсудить что-то без лишних ушей. Чтобы активировать эту функцию наберите 'приватность вкл', деактивировать - 'приватность выкл'. Защитное поле автоматически деактивируется примерно через 20 минут.\n";
    if(privacy) return desc+extra;
    else return desc+"%^RED%^Защита от прослушивания неактивна.";
}
