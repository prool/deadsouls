#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("рысь");
    SetId(({"нпс","моб","кошка","рысь"}));
    SetAdjectives(({"большая"}));
    SetShort("рысь");
    SetLong("Эта большая кошка, размером с собаку, умелый и опасный охотник. Ее большие уши помогают выслеживать добычу в полной темноте.");
    SetWanderSpeed(10);
    SetLevel(1);
    SetMelee(1);
    SetRace("cat");
    SetGender("male");
}
void init(){
    ::init();
}
