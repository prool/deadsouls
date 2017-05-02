#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("минотавр");
    SetId(({"нпс","моб","чудовище","монстр""}));
    SetAdjectives(({"non-player", "ужасное"}));
    SetShort("Минотавр");
    SetLong("Этому ужасному чудовищу было принесено в жертву множество девственниц.");
    SetClass("fighter");
    SetLevel(30);
    SetMelee(1);
    SetRace("demi-god");
    SetGender("male");
}
void init(){
    ::init();
}
