#include <lib.h>

inherit LIB_ROOM;

static void create() {
    object ob;
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Коридор между тестовыми лабораториями");
    SetLong("Это главный коридор ведущий к тестовым лабораториям. На севере вы видите боевую арену. На юге зверинец. Коридор продолжается на запад и восток.");
    SetExits( ([
                "south" : "/domains/default/room/wiz_corr_south",
                "west" : "/domains/default/room/wiz_corr1",
                "north" : "/domains/default/room/arena",
                "east" : "/domains/default/room/wiz_corr_east2.c",
                ]) );
    SetInventory(([
                ]));


    SetDoor("north", "/domains/default/doors/steel_door2.c");

}
int CanReceive(object ob) {
    return room::CanReceive();
}

void init(){
    ::init();
}
