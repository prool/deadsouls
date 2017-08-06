#include <lib.h>
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(0);
    SetShort("Сырой туннель");
    SetLong("Этот темный туннель глубоко врезается в скалу и ведет вниз к подземному источнику, который питает город. На востоке и западе туннель перекрыт решетчатыми дверями.");
    SetItems(([
                ({ "скала", "порода" }) : "Это плотный, твердый материал глубоко под землей.",
                ]));
    SetExits( ([
                "east" : "/domains/town/room/well1",
                "west" : "/domains/town/room/well3.c",
                ]) );
    SetDoor("east", "/domains/town/doors/welldoor1.c");
    SetDoor("west", "/domains/town/doors/welldoor2.c");
    SetFlowLimit(2);
}

void init(){
    ::init();
}
