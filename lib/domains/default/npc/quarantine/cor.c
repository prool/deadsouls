#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("Кор");
    SetId(({"кор"}));
    SetShort("Кор");
    SetLong("Кор - студент по программе обмена из Нидерландов.");
    SetMelee(1);
    SetLevel(5);
    SetRace("human");
    SetGender("male");
    SetNoClean(1);
}
void init(){
    ::init();
}
