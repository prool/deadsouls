#include <lib.h>
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Кухня");
    SetLong("Вы находитесь в очень большой кухне, в которой "
            "с легкостью поместится дюжина поваров. Но, похоже, "
            "что еду готовили тут уже очень давно.");
    SetExits( ([
                "west" : "/domains/town/room/mansion_dhall2.c",
                ]) );
    SetInventory( ([
                "/domains/town/obj/rack" : 1,
                "/domains/town/obj/stove" : 1,
                "/domains/town/npc/rat" : (: random(5)+1 :) ,
                ]) );
}

void init(){
    room::init();
}
