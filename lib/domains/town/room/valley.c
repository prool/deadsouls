#include <lib.h>
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("outdoors");
    SetAmbientLight(30);
    SetNightLight(10);
    SetDayLight(30);
    SetShort("Долина орков");
    SetLong("Вы находитесь в небольшой долине ниже скалистых утесов на западе. Кажется, в этих местах обосновалась банда орков, вы видите их ветхую крепость на севере. Также здесь вы видите две тропы ведущие в лес на восток и юго-запад.");
    SetSkyDomain("town");
    SetExits( ([
        "east" : "/domains/town/room/clearing",
        "north" : "/domains/town/room/orc_fortress",
        "southwest" : "/domains/town/room/narrow_path.c",
      ]) );
    SetInventory(([
        "/domains/town/npc/orc" : 1,
        "/domains/town/npc/orc2" : 1,
      ]) );
}

void init(){
    ::init();
}

int clean_up(int ref_exists){
    return ::clean_up();
}

void reset(){
}
