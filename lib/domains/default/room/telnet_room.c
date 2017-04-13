#include <lib.h>
#include <daemons.h>
#include ROOMS_H

inherit LIB_ROOM;

string LoadIP(){
    if(INTERMUD_D->GetMudList()["Dead Souls Dev"]){
        return INTERMUD_D->GetMudList()["Dead Souls Dev"][1];
    }
    else return "127.0.0.1";
}

string LoadPort(){
    if(INTERMUD_D->GetMudList()["Dead Souls Dev"]){
        return INTERMUD_D->GetMudList()["Dead Souls Dev"][2];
    }
    else return ""+query_host_port();
}

void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("узел связи");
    SetLong("Отсюда вы можете попытаться "+
            "связаться с разработчиками. Это бывает полезно "+
            "если у вас есть вопросы, а intermud не работает. "+
            "Note that being in charmode interferes with input. "+
            "\n\tIf the connection "+
            "fails, email cratylus@comcast.net to ask for help. "+
            "Once you connect to Dead Souls Dev, type \"dcon\" to "+
            "return to your own mud. \n\n"+
            "To connect type \"connect\" \n"+
            "К западу отсюда зал билдеров.");
    SetExits( ([ 
                "west" : "/domains/default/room/wiz_hall2",
                ]) );
    SetNoModify(1);
}

void init(){
    object ding;
    ::init();
    if(!present("telnet_room_client",this_player())){
        ding=new("/secure/obj/tc");
        ding->eventMove(this_player());
        ding->SetConnection(LoadIP()+" "+LoadPort());
    }
}

int CanRelease(object ob){
    if(present("telnet_room_client",ob)){
        present("telnet_room_client",ob)->eventDestruct();
    }
    return 1;
}

int CanReceive(object ob) {
    if(interactive(ob)){
        tell_object(this_object(),ob->GetName()+" готовится войти в узел связи.");
    }
    return 1;
}
