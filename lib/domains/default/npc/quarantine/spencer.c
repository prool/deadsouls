#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("Спенсер");
    SetId(({"спенсер"}));
    SetShort("Спенсер");
    SetLong("Спенсер - студент по программе обмена из Великобритании.");
    SetLevel(5);
    SetRace("human");
    SetGender("male");
    SetNoClean(1);
}
void init(){
    ::init();
}
