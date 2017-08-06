#include <terrain_types.h>
#include <lib.h>
inherit LIB_ROOM;

int readSign() {
    this_player()->more("/domains/town/txt/hints_sign.txt");
    return 1;
}

static void create() {
    room::create();
    SetClimate("outdoors");
    SetAmbientLight(30);
    SetShort("Большой перекресток");
    SetNightLong("Вы вышли на большой перекресток, освещенный фонарным столбом. Главная дорога тянется с севера на юг и пересекается с дорогой ведущей с востока с побережья на запад в пустошь. \n%^GREEN%^Здесь есть табличка, которую можно прочесть.%^RESET%^");
    SetDayLong("Вы вышли на большой оживленный перекресток. Главная дорога тянется с севера на юг и пересекается с дорогой ведущей с востока с побережья на запад в пустошь.\n%^GREEN%^Здесь есть табличка, которую можно прочесть.%^RESET%^");
    SetItems( ([
        "табличка":"У перекрестка установлена большая табличка. Чтобы прочесть ее, попробуйте 'читать табличку'.",
      ]) );
    SetSkyDomain("town");
    SetExits( ([
        "south" : "/domains/town/room/south_road1",
        "east" : "/domains/town/room/vill_road2",
        "west" : "/domains/town/room/road1",
        "north" : "/domains/town/room/road0.c",
      ]) );
    AddTerrainType(T_ROAD);
    SetNoModify(0);
    SetInventory(([
        "/domains/town/obj/clocktower" : 1,
      ]));
    SetEnters( ([
      ]) );
    SetRead("табличку", (: readSign :) );
    AddItem(new("/domains/town/obj/lamp"));
}

void init(){
    ::init();
}
