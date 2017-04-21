#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("гнолл");
    SetAdjectives( ({"большой", "грязный", "ужасный"}) );
    SetId( ({"гнолл", "гибрид"}) );
    SetShort("большой грязный гнолл");
    SetLong("Это ужасный гибрид человека и гиены. На его грязной шкуре вы замечаете пятна засохшей крови и фекалий, а с его пасти постоянно капает слюна.");
    SetLevel(1);
    SetMelee(1);
    SetRace("gnoll");
    SetGender("male");
}
void init(){
    ::init();
}
