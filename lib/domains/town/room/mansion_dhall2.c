#include <lib.h>
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Нижний этаж особняка");
    SetLong("Вы находитесь в красиво оформленной прихожей на нижнем этаже особняка. "
            "На востоке и западе вы видите другие комнаты, а на юге продолжается коридор. "
            "Также на севере находится входное фойе.");
    SetItems( ([ 
                "прихожая" : "Отсюда можно попасть в другие "
                "части дома.",
                ({"особняк","дом"}) : "Вы находитесь в великолепном особняке.",
                "фойе" : "Вход в особняк на севере отсюда."
                ]) );
    SetExits( ([
                "north" : "/domains/town/room/mansion_int",
                "south" : "/domains/town/room/mansion_dhall3",
                "west" : "/domains/town/room/mansion_room10",
                "east" : "/domains/town/room/mansion_room7.c",
                ]) );

}
void init(){
    ::init();
}
