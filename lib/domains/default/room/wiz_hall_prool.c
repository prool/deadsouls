#include <lib.h>
#include ROOMS_H

inherit LIB_ROOM;

string LongDesc(){
    string desc = "Пустая комната с белыми стенами\nНа одной из стен написано Это первая комната, созданная Прулём\n";
	desc += "Также на стене написана цифра 2";
    return desc;
}

static void create() {
    object ob;
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Комната Пруля #1");
    SetLong( (: LongDesc :) );
    SetProperty("no attack", 1);
    SetProperty("nopeer",1);
    SetExits( ([
                "east" : "/domains/default/room/wiz_hall",
                ]) );
}

int CanReceive(object ob) {
    return room::CanReceive();
}

void init(){
    ::init();
}
