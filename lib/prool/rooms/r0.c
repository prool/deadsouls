#include <lib.h>
#include ROOMS_H

inherit LIB_ROOM;

string LongDesc(){
    string desc = "Проход в зону Пруля, простирающуюся на западе (west)\n";
    return desc;
}

static void create() {
    object ob;
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Проход в зону Пруля");
    SetLong( (: LongDesc :) );
    SetProperty("no attack", 1);
    SetProperty("nopeer",1);
    SetExits( ([
                "east" : "/domains/default/room/пруль2",
                "восток" : "/domains/default/room/пруль2",
		"west" : "/prool/rooms/r1",
		"запад" : "/prool/rooms/r1"
                ]) );
}


int CanReceive(object ob) {
    return room::CanReceive();
}

void init(){
    ::init();
}
