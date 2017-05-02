#include <position.h>
#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("моль");
    SetId(({"нпс","моб","моль","насекомое"}));
    SetAdjectives(({"летающее", "крохотная"}));
    SetShort("крохотная моль");
    SetLong("Самое обычное насекомое, обладающее необычным пристрастием к старой одежде.");
    SetWimpy(80);
    SetPosition(POSITION_FLYING);
    SetLevel(1);
    SetMelee(1);
    SetRace("insect");
    SetMaxHealthPoints(2);
    SetGender("male");
}
void init(){
    ::init();
}
