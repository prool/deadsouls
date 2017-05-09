#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("Симон");
    SetId(({"симон"}));
    SetShort("Симон");
    SetLong("Симон - студент по программе обмена из Великобритании.");
    SetLevel(5);
    SetRace("human");
    SetGender("male");
    SetNoClean(1);
}
void init(){
    ::init();
}
