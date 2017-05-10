#include <lib.h>

inherit LIB_SENTIENT;


static void create() {
    sentient::create();
    SetKeyName("Тед");
    SetId(({"тед"}));
    SetShort("Тед");
    SetLong("Тед - студент Виртуального лагеря.");
    SetLevel(5);
    SetRace("human");
    SetGender("male");
    SetNoClean(1);
}
void init(){
    ::init();
}
