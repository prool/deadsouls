#include <lib.h>
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Комната прислуги");
    SetLong("В этой комнате царит спартанская пустота. "
      "Видимо прислуга сменялась каждые несколько часов "
      "и подолгу тут не задерживалась.");
    SetInventory( ([
        "/domains/town/obj/cot" :1,
      ]) );
    SetExits( ([
        "east" : "/domains/town/room/mansion_uhall3"
      ]) );

    SetDoor("east", "/domains/town/doors/m6.c");

}
void init(){
    ::init();
}
