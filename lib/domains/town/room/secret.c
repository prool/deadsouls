#include <lib.h>
#include ROOMS_H

inherit LIB_ROOM;

void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(0);
    SetShort("Секретный тайник");
    SetLong("Кажется, это секретная комната для сохранения переменных. "+
            "Главная спальня находится на западе.");
    SetExits( ([ "west" : "/domains/town/room/mansion_mbdroom" ]) );
    SetNoClean(1);
    SetPersistent(1);
    RestoreObject();
}

void init(){
    ::init();
}
