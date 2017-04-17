#include <position.h>
#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("лутечая мышь");
    SetId(({"нпс","моб","существо","животное"}));
    SetAdjectives(({"летучая", "обычная"}));
    SetShort("летучая мышь");
    SetLong("Самая обычная летучая мышь, размером в половину вашей руки.");
    SetWimpy(80);
    SetPermitLoad(1);
    SetPosition(POSITION_FLYING);
    SetWanderSpeed(1);
    SetLevel(1);
    SetMelee(1);
    SetRace("bat");
    SetMaxHealthPoints(20);
    SetGender("male");
    SetMessage("leave","$N сбежала $D.");
}
void init(){
    ::init();
}
