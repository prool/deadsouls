#include <terrain_types.h>
#include <lib.h>
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("outdoors");
    SetAmbientLight(30);
    SetShort("Западная дорога");
    SetDayLong("Вы находитесь на оживленной дороге ведущей из города с востока на запад. На севере вы видите здание церкви.");
    SetSkyDomain("town");
    SetExits( ([ 
        "north" : "/domains/town/room/church",
        "east" : "/domains/town/room/start",
        "west" : "/domains/town/room/road2",
      ]) );
    SetNightLong("Вы находитесь на освещенной лампами дороге ведущей из города с востока на запад. На севере вы видите здание церкви.");
    AddTerrainType(T_ROAD);
    AddItem(new("/domains/town/obj/lamp"));
}
void init(){
    ::init();
}
