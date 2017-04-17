#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("корова");
    SetId(({"нпс","моб","существо","животное"}));
    SetAdjectives(({"короткошерстная", "non player"}));
    SetShort("короткошерстная корова");
    SetLong("Эта порода коров славится своим великолепным деликатесным мясом. Поэтому их откармливают трижды в день свежей травой и массажирует их тело утром и вечером.");
    SetWimpy(80);
    SetWanderSpeed(7);
    SetLevel(1);
    SetMelee(1);
    SetRace("cow");
    SetGender("female");
    SetAction(1, ({ "!emote rit." }) );
}
void init(){
    ::init();
}
