#include <lib.h>
#include ROOMS_H

inherit LIB_ROOM;

int tutorial = 0;

string DoDesc(){
    string desc = "Добро пожаловать! Чтобы войти в город наберите: %^%^GREEN%^%^enter town%^%^RESET%^%^\n\n";
    string desc2 = "Чтобы начать обучение наберите: %^%^RED%^%^enter tutorial\n\n%^%^RESET%^%^";
    return desc + ( tutorial ? desc2 : "");
}

void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Начало игры");
    SetLong( (: DoDesc :));
    SetExits( ([ 
                "south" : "/domains/default/room/wiz_hall",
                ]) );
    SetNoModify(1);
    SetCoordinates("5000,5000,0");
    SetItems( ([
                "обучение" : "Это несколько специальных комнат, чтобы познакомить вас с игрой.",
                "town" : "Главный город этого мира.",
                ]) );
    SetEnters( ([
                //"tutorial" : "/domains/tutorial/room/start",
                "town" : "/domains/town/room/start",
                ]) );
    if(tutorial){
        AddEnter("tutorial", "/domains/tutorial/room/start");
    }
}

void init(){
    ::init();
}
