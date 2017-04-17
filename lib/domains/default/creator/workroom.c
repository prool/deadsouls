#include <lib.h>

inherit LIB_ROOM;

static void create() {

    room::create();
    SetClimate("indoors");
    SetAmbientLight(40);
    SetShort("мастерская Создателя");
    SetLong("Вы находитесь в мастерской Создателя."+
            " Стартовая комната внизу под вами..");
    SetItems( ([ 
                "workroom" : "Выглядит очень круто.",
                ]) );
    SetInventory(([
                ]));
    SetObviousExits("down");
    SetExits( ([ "down" : "/domains/default/room/start.c",
                ]) );
}

