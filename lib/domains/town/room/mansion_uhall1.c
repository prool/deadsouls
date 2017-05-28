#include <lib.h>
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Верхний коридор особняка, север");
    SetLong("Вы находитесь в украшенном картинами верхнем коридоре особняка. "
      "На востоке и западе вы видите комнаты, а коридор продолжается на юг. "
      "Открытое окно в конце коридора "
      "ведет вниз.");
    SetItems( ([
        ({"окно","открытое окно"}) : "Открытое окно "+
        "ведет вниз, к выходу из особняка.",
        ({"коридор","верхний коридор"}) : "По нему можно "+
        "попасть из одной части особняка в другую."
      ]) );
    SetExits( ([
        "down" : "/domains/town/room/mansion_ext",
        "south" : "/domains/town/room/mansion_uhall2",
        "east" : "/domains/town/room/mansion_room1",
        "west" : "/domains/town/room/mansion_room2",
        "window" : "/domains/town/room/mansion_ext"
      ]) );
    SetEnters( ([
        "window" : "/domains/town/room/mansion_ext"
      ]) );

    SetDoor("east", "/domains/town/doors/m1.c");

    SetDoor("west", "/domains/town/doors/m2.c");

}
void init(){
    ::init();
}
