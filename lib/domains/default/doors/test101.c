#include <lib.h>

inherit LIB_DOOR;

static void create() {
    door::create();

    SetSide("west", ([ "id" : ({"стальная дверь", "запад", "дверь", "западная дверь"}),
                "short" : "стальная дверь ведущая на запад",
                "long" : "Это восточная сторона двери ведущей на запад.",
                "lockable" : 1 ]) );

    SetSide("east", ([ "id" : ({"стальная дверь", "восток", "дверь", "восточная дверь"}),
                "short" : "стальная дверь ведущая на восток",
                "long" : "Это западная сторона двери ведущей на восток.",
                "lockable" : 1 ]) );

    SetClosed(1);
    SetLocked(0);
    SetKeys("west", ({ "west key" }));
    SetKeys("east", ({ "east key" }));
}

void init(){
    ::init();
}
