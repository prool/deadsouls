#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("квижибо");
    SetId(({"нпс","моб","существо","квижибо"}));
    SetAdjectives(({"толстый","лысый","получеловек","полуобезьяна"}));
    SetShort("квижибо");
    SetLong("Вы видите толстого лысого получеловека-полуобезьяну.");
    SetWanderSpeed(20);
    SetClass("fighter");
    SetLevel(10);
    SetEncounter(100);
    SetMelee(1);
    SetRace("ape");
    SetGender("male");
}
void init(){
    ::init();
}
