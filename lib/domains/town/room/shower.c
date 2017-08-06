#include <lib.h>
inherit LIB_ROOM;
static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Душевая кабинка");
    SetLong("Вы зашли в душевую кабинку. "
            "Здесь моются люди.");
    SetExits( ([
                "out" : "/domains/town/room/mansion_room3"
                ]) );
    SetObviousExits("out");
}

void init(){
    ::init();
}
