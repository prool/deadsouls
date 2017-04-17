#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("коза");
    SetId(({"нпс","моб","существо","животное"}));
    SetAdjectives(({"non-player", "non player"}));
    SetShort("коза");
    SetLong("Типичный представитель своего вида: нервная и упрямая, но по-своему грациозная. Все что она хочет, это вкусно поесть и оставить побольше потомства.");
    SetWanderSpeed(4);
    SetLevel(1);
    SetMelee(1);
    SetRace("deer");
    SetGender("female");
}
void init(){
    ::init();
}
