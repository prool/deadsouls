#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("балрог");
    SetId(({"нпс","моб","существо","демон"}));
    SetAdjectives(({"жестокий","ужасный"}));
    SetShort("жестокий балрог");
    SetLong("Это ужасный демон из вашего самого страшного кошмара!");
    SetWanderSpeed(5);
    SetClass("fighter");
    SetMelee(1);
    SetLevel(50);
    SetRace("balrog");
    SetGender("male");
}
void init(){
    ::init();
}
