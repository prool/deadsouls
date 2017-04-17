#include <lib.h>

inherit LIB_DOOR;

static void create() {
    door::create();

    SetSide("DIR_X", ([ "id" : ({"дверь ведущая на DIR_X", "дверь", "DIR_X дверь"}),
                "short" : "дверь ведущая на DIR_X",
                "long" : "Это Y_SIDE сторона двери ведущей на DIR_X.",
                "lockable" : 1 ]) );

    SetSide("DIR_Y", ([ "id" : ({"дверь ведущая на DIR_Y", "дверь", "DIR_Y дверь"}),
                "short" : "дверь ведущая на DIR_Y",
                "long" : "Это X_SIDE сторона двери ведущей на DIR_Y.",
                "lockable" : 1 ]) );

    SetClosed(1);
    SetLocked(0);
    SetKeys("DIR_X", ({ "DIR_X key" }));
    SetKeys("DIR_Y", ({ "DIR_Y key" }));
}

void init(){
    ::init();
}
