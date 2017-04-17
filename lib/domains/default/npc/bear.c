#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("медведь");
    SetId(({"нпс","моб","существо","животное"}));
    SetAdjectives(({"большой", "бурый"}));
    SetShort("медведь");
    SetLong("Это большой бурый медведь. Он не так огромен как гризли, но достаточно велик, чтобы положить вас одним ударом лапы.");
    SetWanderSpeed(20);
    SetClass("fighter");
    SetLevel(10);
    SetMelee(1);
    SetRace("bear");
    SetGender("male");
}
void init(){
    ::init();
}
