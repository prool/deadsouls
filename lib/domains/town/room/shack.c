#include <lib.h>
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(25);
    SetShort("Лачуга садовника");
    SetLong("Вы зашли в темную деревянную будку садовника. "
            "Из-за пыли и ржавчины очевидно, что "
            "лачуга уже довольно давно заброшена.");
    SetExits( ([
                "south" : "/domains/town/room/garden",
                "out" : "/domains/town/room/garden.c",
                ]) );
    SetInventory(([
                "/domains/town/obj/rayovac" : 1,
                "/domains/town/obj/ladder" : 1,
                ]) );

}
void init(){
    ::init();
}
