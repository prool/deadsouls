#include <lib.h>
#include ROOMS_H

inherit LIB_ROOM;

void create() {
    room::create();
    SetAmbientLight(30);
    SetShort("Ничто");
    SetLong("Вы нигде.  Идите вниз, чтобы выйти отсюда.");
    SetExits( ([ "down" : ROOM_START ]) );
    SetNoModify(1);
}
void init(){
    ::init();
}
