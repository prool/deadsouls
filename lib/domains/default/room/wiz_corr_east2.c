#include <lib.h>

inherit LIB_ROOM;

static void create() {
    object ob;
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Коридор между тестовыми лабораториями, восток");
    SetLong("Это главный коридор ведущий к тестовым лабораториям. Коридор продолжается на запад и восток. На юге вы видите обсерваторию.");
    SetExits( ([
                "east" : "/domains/default/room/wiz_corr_east3",
                "west" : "/domains/default/room/wiz_corr_east",
                "south" : "/domains/default/room/stargate_lab.c",
                ]) );
    SetProperty("no attack", 1);
}

int CanReceive(object ob) {
    return room::CanReceive();
}

void init(){
    ::init();
}
