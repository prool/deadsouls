#include <lib.h>
#include ROOMS_H

inherit LIB_ROOM;

string LongDesc(){
    string desc = "Пограничный пост зоны Пруля\n";
    return desc;
}

static void create() {
    object ob;
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Пограничный Пост зоны Пруля");
    SetLong( (: LongDesc :) );
    SetProperty("no attack", 1);
    SetProperty("nopeer",1);
    SetInventory(([
			"/prool/objs/book" : 1
		]));
    SetExits( ([
                "east" : "/prool/rooms/r0",
                "восток" : "/prool/rooms/r0"
                ]) );
}

int CanReceive(object ob) {
    return room::CanReceive();
}

void init(){
    ::init();
}
