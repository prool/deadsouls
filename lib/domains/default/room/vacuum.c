#include <lib.h>
#include ROOMS_H
#include <respiration_types.h>

inherit LIB_ROOM;

void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Безвоздушное пространство");
    SetLong("Комната единственное предназначение которой - препятствовать дыханию.");
    SetRespirationType(R_VACUUM);
}

void init(){
    ::init();
}
