#include <lib.h>

inherit LIB_SENTIENT;


static void create() {
    sentient::create();
    SetKeyName("Том");
    SetId(({"том"}));
    SetShort("Том");
    SetLong("Том - студент Виртуального лагеря.");
    SetLevel(5);
    SetRace("human");
    SetGender("male");
    SetNoClean(1);
}
void init(){
    ::init();
}
