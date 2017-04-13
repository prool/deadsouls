#include <lib.h>
#include ROOMS_H

inherit LIB_ROOM;

void create() {
    room::create();
    SetAmbientLight(30);
    SetShort("встроенный модуль");
    SetLong("Встроенный модуль: некоторые объекты перемещаются сюда при создании "+
            "и идентификации. Чтобы выйти отсюда - идите вниз.");
    SetExits( ([ "down" : ROOM_START ]) );
}
int CanReceive(object ob){
    return room::CanReceive(ob);
}
