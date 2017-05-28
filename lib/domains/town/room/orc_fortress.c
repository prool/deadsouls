#include <lib.h>
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(15);
    SetShort("Орочья крепость");
    SetLong("Вы остановились у входа в местную орочью крепость. Она кажется грубой и очень простой, но от того не менее враждебной. Выход отсюда находится на юге, а на западе вы видите какое-то помещение.");
    SetExits( ([
                "south" : "/domains/town/room/valley",
                "west" : "/domains/town/room/orc_temple.c",
                ]) );
    SetSmell( ([ "default" : "Здесь витает зловоние мусора и экскрементов животных."]) );
    SetInventory(([
                "/domains/town/npc/orc" : 1,
                "/domains/town/npc/orc2" : 1,
                "/domains/town/npc/orc_boss" : 1,
                ]));
}
void init(){
    ::init();
}
