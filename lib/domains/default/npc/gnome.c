#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("гном");
    SetAdjectives( ({"милый", "маленький"}) );
    SetId(({"нпс","моб","существо","гном"}));
    SetShort("маленький милый гном");
    SetLong("Этот гном похож на карлика, только он поменьше и более пропорционально сложен. Также у него белая шикарная борода.");
    SetLevel(1);
    SetMelee(1);
    SetRace("gnome");
    SetGender("male");
}
void init(){
    ::init();
}
