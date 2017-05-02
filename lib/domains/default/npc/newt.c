#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("тритон");
    SetAdjectives( ({"скользкий","скользкая","мерзкая"}) );
    SetId(({"нпс","моб","тритон","амфибия"}));
    SetShort("тритон");
    SetLong("Это мерзкая и скользкая амфибия.");
    SetWimpy(80);
    SetWanderSpeed(3);
    SetMelee(1);
    SetLevel(1);
    SetRace("amphibian");
    SetClass("explorer");
    SetMaxHealthPoints(10);
    SetGender("male");
}
void init(){
    ::init();
}
