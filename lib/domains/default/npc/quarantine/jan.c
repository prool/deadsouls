#include <lib.h>

inherit LIB_SENTIENT;


static void create() {
    sentient::create();
    SetKeyName("jan");
    SetId(({"jan"}));
    SetShort("Jan");
    SetLong("Jan is a foreign exchange student from the Netherlands.");
    SetLevel(5);
    SetRace("human");
    SetGender("male");
    SetNoClean(1);
}
void init(){
::init();
}
