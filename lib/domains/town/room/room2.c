#include <lib.h>
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("outdoors");
    SetAmbientLight(30);
    SetShort("Прототип комнаты");
    SetLong("Здесь ничего нет, вообще ничего.");
}
void init(){
    ::init();
}
