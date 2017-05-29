#include <lib.h>
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Верхняя ванная");
    SetLong("Вы зашли в ванную комнату. Она выглядит слишком, "
      "обычной для такого шикарного особняка, но кажется "
      "чистой и исправной. Здесь есть также "
      "душевая кабинка.");
    SetItems( ([
        ({"кабинка","душевая кабинка","душ" })  : "Самая обычная душевая кабинка.",
        ({"раковина","умывальник" })  : "Здесь умываются.",
      ]) );
    SetExits( ([
        "west" : "/domains/town/room/mansion_uhall2"
      ]) );
    SetInventory( ([
        "/domains/town/obj/toilet" : 1,
        "/domains/town/obj/mat" : 1
      ]) );
    SetEnters( ([
        "кабинка" : "/domains/town/room/shower",
        "душевая кабинка" : "/domains/town/room/shower",
        "душ" : "/domains/town/room/shower"
      ]) );

    SetDoor("west", "/domains/town/doors/m3.c");

}
void init(){
    ::init();
}
