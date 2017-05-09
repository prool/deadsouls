#include <lib.h>

inherit LIB_SENTIENT;


static void create() {
    sentient::create();
    SetKeyName("Валлас");
    SetId(({"валлас"}));
    SetShort("Валлас");
    SetLong("Валлас - студент по программе обмена из Великобритании.");
    SetLevel(5);
    SetRace("human");
    SetGender("male");
    SetNoClean(1);
}
void init(){
    ::init();
}
