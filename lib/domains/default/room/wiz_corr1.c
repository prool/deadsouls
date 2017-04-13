#include <lib.h>

inherit LIB_ROOM;

static void create() {
    object ob;
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Коридор между тестовыми лабораториями, запад");
    SetLong("Это западный конец основного коридора между тестовыми лабораториями. На севере вы видите лабораторию болезней. Залы билдеров на западе, а коридор продолжается на восток.");
    SetExits( ([ 
                "north" : "/domains/default/room/quarantine1",
                "east" : "/domains/default/room/wiz_corr_east",
                "west" : "/domains/default/room/wiz_hall",
                ]) );

    SetInventory(([
                ]));

    SetProperty("no attack", 1);

}
int CanReceive(object ob) {
    return room::CanReceive();
}

void init(){
    ::init();
}
