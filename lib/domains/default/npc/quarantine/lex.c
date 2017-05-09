#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("Лекс");
    SetId(({"лекс"}));
    SetShort("Лекс");
    SetLong("Лекс - студент по программе обмена из Нидерландов.");
    SetMelee(1);
    SetLevel(5);
    SetRace("human");
    SetGender("male");
    SetNoClean(1);
}
void init(){
    ::init();
}
