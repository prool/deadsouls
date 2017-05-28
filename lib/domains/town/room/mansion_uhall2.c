#include <lib.h>
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Верхний коридор особняка");
    SetLong("Вы находитесь в украшенном картинами верхнем коридоре особняка. "
      "На востоке и западе вы видите комнаты, а коридор продолжается на "
      "север и юг."); 
    SetItems( ([
        ({"коридор","верхний коридор"}) : "По нему можно "+
        "попасть из одной части особняка в другую."
      ]) );
    SetExits( ([
        "south" : "/domains/town/room/mansion_uhall3",
        "north" : "/domains/town/room/mansion_uhall1",
        "east" : "/domains/town/room/mansion_room3",
        "west" : "/domains/town/room/mansion_room4"
      ]) );

    SetDoor("west", "/domains/town/doors/m4.c");

    SetDoor("east", "/domains/town/doors/m3.c");

}
void init(){
    ::init();
}
