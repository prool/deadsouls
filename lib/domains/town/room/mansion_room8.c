#include <lib.h>
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Большой зал");
    SetLong("Эта огромная комната впечатляет как по размеру, так и по оформлению. "
            "Находясь в самом центре особняка, "
            "этот зал легко мог вместить сотни гостей. "
            "Сводчатые высокие потолки и полированные мраморные полы "
            "покрыты прекрасными "
            "причудливыми узорами.");
    SetExits( ([
                "east" : "/domains/town/room/mansion_dhall3"
                ]) );
}
void init(){
    ::init();
}
