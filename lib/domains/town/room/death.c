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
    SetShort("В пустоте");
    SetLong( (:FunkyPic:) );
    SetObviousExits("no exit");
    set_heart_beat(10);
    SetNoModify(1);
}

void init(){
    ::init();
    add_action("regenerate","восстановиться");
    add_action("wander","блуждать");
    this_object()->CheckChat();
}

string FunkyPic(){
    return read_file("/domains/default/etc/death.txt");
}

int regenerate(){
    write("Вас окатила волна огромной энергии и воссоединила вас "+
            "с вашим телом, вы восскресли в знакомом месте...");
    this_player()->eventRevive();
    this_player()->eventMoveLiving(ROOM_START);
    return 1;
}

int wander(){
    write("Клокочущий хаос вокруг выталкивает вас отсюда, как будто бы "+
            "вы здесь совершенно чужой... "+
            "Вы обнаруживаете себя в знакомом месте, хотя оно выглядит немного по другому.");
    this_player()->eventMoveLiving(ROOM_START);
    return 1;
}

void heart_beat(){
    tell_room(this_object(), "Голоса шепчут: \" Ты можешь "+
            "восстановиться здесь в новое тело.\"");
    return;
}


int CanRelease(object ob){
    if(userp(ob) && ob->GetGhost() && environment(ob) == this_object()) {
        tell_player(ob,"\n%^RED%^Ваш бессмертный дух призван и вы покидаете "+
                "мир мертвых, новое тело восстанавливается вокруг вас. "+
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

