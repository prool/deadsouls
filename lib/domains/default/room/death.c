#include <lib.h>
#include <dirs.h>
#include ROOMS_H

inherit LIB_ROOM;

string FunkyPic();
int CheckChat();
int StartHeart(object ob);

static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("конец пути смертного");
    SetLong( (:FunkyPic:) );
    SetObviousExits("no exit");
    set_heart_beat(10);
    SetNoModify(1);
}

void init(){
    ::init();
    add_action("regenerate","regenerate");
    add_action("wander","wander");
    this_object()->CheckChat();
}

string FunkyPic(){
    return read_file("/domains/default/etc/death.txt");
}

int regenerate(){
    write("Вас подхватывает мощный поток энергии, который "+
            "материализует вас и выбрасывает в знакомом месте...");
    this_player()->eventRevive();
    this_player()->eventMoveLiving(ROOM_START);
    return 1;
}

int wander(){
    write("Все вокруг вас пульсирует и клокочет. "+
            "Какая-то неведомая сила выталкивает вас отсюда и "+
            "вы обнаруживаете себя в как-будто знакомом месте.");
    this_player()->eventMoveLiving(ROOM_START);
    return 1;
}

void heart_beat(){
    tell_room(this_object(), "Вы слышите тихий шепот: \" Здесь ты можешь "+
            "regenerate в новое тело.\"");
    return;
}


int CanRelease(object ob){
    if(userp(ob) && ob->GetGhost() && environment(ob) == this_object()) {
        tell_player(ob,"\n%^RED%^Ваш бессмертный дух призван и вы покидаете "+
                "мир мертвых, новое тело материализуется вокруг вас. "+
                "Вы снова живы!%^RESET%^\n");
        ob->eventRevive();
    }
    return 1;
}

int CanReceive(object ob){
    if(!living(ob)){
        return 0;
    }
    return ::CanReceive(ob);
}


