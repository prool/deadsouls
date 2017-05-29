#include <lib.h>
#include ROOMS_H

inherit LIB_ROOM;

string LongDesc(){
    string desc = "Пустая комната с белыми стенами\nНа одной из стен написано Это 2-я комната, созданная Прулём\n";
	desc += "Имя файла этой комнаты и описание написано кириллицей в кодировке UTF-8";
    return desc;
}

static void create() {
    object ob;
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Комната Пруля #2");
    SetLong( (: LongDesc :) );
    SetProperty("no attack", 1);
    SetProperty("nopeer",1);
    SetInventory(([
			"/obj/meal2" : 1
		]));
    SetExits( ([
                "east" : "/domains/default/room/wiz_hall_prool",
                "восток" : "/domains/default/room/wiz_hall_prool",
		"west" : "/prool/rooms/r0",
		"запад" : "/prool/rooms/r0"
                ]) );
}


int CanReceive(object ob) {
    return room::CanReceive();
}

void init(){
    ::init();
}
