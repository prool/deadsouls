#include <lib.h>
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Фойе особняка");
    SetLong("Вы в фойе огромного, величественного особняка. "
            "Хотя здесь повсюду толстый слой пыли, это место все равно выглядит красиво. "
            "На юге вы замечаете коридор."); 
    SetItems( ([
                "фойе" : "Здесь находится входная дверь "
                "особняка.",
                ({"коридор","прихожая"}) : "Широкий коридор "
                "ведет на юг вглубь особняка.",
                "пыль" : "Серая, жирная на ощупь пыль "
                "покрывает все вокруг."
                ]) );
    SetExits( ([
                "north" : "/domains/town/room/mansion_ext",
                "south" : "/domains/town/room/mansion_dhall2",
                "east" : "/domains/town/room/mansion_room9.c",
                ]) );
    SetDoor("north","/domains/town/doors/mansion");
}
void init(){
    ::init();
}
