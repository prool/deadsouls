#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("гоблин");
    SetAdjectives( ({"вредное", "зеленый"}) );
    SetId(({"нпс","гоблин","существо","монстр"}));
    SetShort("зеленый гоблин");
    SetLong("Это вредное существо - подтверждение самых ужасных историй, слышанных вами в детстве. Он как-будто светится злобой и ненавистью. Само его присутствие отравляет воздух.");
    SetLevel(1);
    SetMelee(1);
    SetRace("goblin");
    SetGender("male");
}
void init(){
    ::init();
}
