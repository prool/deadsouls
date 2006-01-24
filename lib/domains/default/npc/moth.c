#include <position.h>
#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("moth");
    SetId(({"npc","mob","character","mobile"}));
    SetAdjectives(({"non-player", "non player"}));
    SetShort("a tiny moth");
    SetLong("An ordinary flying insect which has a particular taste for old clothes.");
    SetPosition(POSITION_FLYING);
    SetLevel(1);
    SetMelee(1);
    SetRace("insect");
    SetGender("male");
}
void init(){
    ::init();
}
