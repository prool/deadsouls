#include <lib.h>
#include ROOMS_H

inherit LIB_ROOM;

void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Начальная комната");
    SetLong("Начальная комната этого места. Чтобы войти "+
            "в примеры комнат идите вниз.");
    SetExits( ([ 
                "down" : "/domains/town/room/road",
                ]) );
}
void init(){
    ::init();
}
