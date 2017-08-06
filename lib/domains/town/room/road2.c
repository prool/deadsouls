#include <terrain_types.h>
#include <lib.h>
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("outdoors");
    SetAmbientLight(30);
    SetShort("Западная дорога");
    SetNightLong("Вы находитесь на оживленной дороге, освещенной лампами. Она ведет с востока из города на запад к старому горбатому мосту. На севере вы видите здание большого особняка.");
    SetDayLong("Вы находитесь на оживленной дороге, ведущей с востока из города на запад к старому горбатому мосту. На севере вы видите здание большого особняка.");
    SetSkyDomain("town");
    SetExits( ([
        "east" : "/domains/town/room/road1",
        "west" : "/domains/town/room/bridge",
        "south" : "/domains/town/room/gate.c",
      ]) );
    AddTerrainType(T_ROAD);
    AddItem(new("/domains/town/obj/lamp"));
}

void init(){
    ::init();
    if(mud_name() == "Dead Souls Omega" && !GetExit("north")){
    }
}
