#include <lib.h>
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Гостевая комната, восточная часть");
    SetLong("Вы находитесь в восточной части гостевой комнаты особняка. "
      "Она роскошно обставлена и меблирована. "
      "Состояние постели говорит о том, что кто-то здесь недавно "
      "оставался.");
    SetItems( ([
        ({"мебель","обстановка"}) : "Все очень удобное и привлекательное."
      ]) );
    SetExits( ([
        "west" : "/domains/town/room/mansion_uhall1"
      ]) );
    SetInventory(([
        "/domains/town/obj/obag" :1,
        "/domains/town/obj/gbed" :1,
        "/domains/town/armor/boot_l" :1,
        "/domains/town/armor/boot_r" :1,
      ]) );

    SetDoor("west", "/domains/town/doors/m1.c");

}
void init(){
    ::init();
}
