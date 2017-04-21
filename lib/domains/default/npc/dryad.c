#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("дриада");
    SetAdjectives( ({"древесная", "диковатая", "заплутавшая"}) );
    SetId( ({"дриада"}) );
    SetShort("древесная дриада");
    SetLong("На первый взгляд это диковатая девушка. Но на самом деле это заплутавшая лесная полу-богиня.");
    SetLevel(1);
    SetMelee(1);
    SetRace("dryad");
    SetGender("female");
}
void init(){
    ::init();
}
