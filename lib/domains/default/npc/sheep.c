#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("овца");
    SetId(({"нпс","моб","животное"}));
    SetAdjectives(({"любящая", "обычная"}));
    SetShort("овца");
    SetLong("Это самая обычная овца, любящая жевать и проглатывать зелень. Благодаря этому на ней великолепная шубка из теплой и мягкой шерсти.");
    SetLevel(1);
    SetMelee(1);
    SetRace("sheep");
    SetGender("female");
}
void init(){
    ::init();
}
