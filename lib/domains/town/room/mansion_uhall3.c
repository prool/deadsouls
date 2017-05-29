#include <lib.h>
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Верхний коридор особняка, юг");
    SetLong("Вы находитесь в украшенном картинами верхнем коридоре особняка. "
      "На востоке и западе вы видите комнаты, а коридор продолжается на север. "
      "Спальня владельца особняка находится на юге. "
      "Огромная мраморная лестница ведет вниз, "
      "на нижний этаж."); 
    SetItems( ([
        ({"коридор","верхний коридор"}) : "По нему можно "+
        "попасть из одной части особняка в другую."
      ]) );

    SetExits( ([
        "south" : "/domains/town/room/mansion_mbdroom",
        "north" : "/domains/town/room/mansion_uhall2",
        "down" : "/domains/town/room/mansion_dhall3",
        "east" : "/domains/town/room/mansion_room5",
        "west" : "/domains/town/room/mansion_room6"
      ]) );

    SetDoor("east", "/domains/town/doors/m5.c");

    SetDoor("west", "/domains/town/doors/m6.c");

    SetDoor("south", "/domains/town/doors/m7.c");

}
void init(){
    ::init();
}
