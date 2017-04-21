#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("карлик");
    SetId(({"нпс","моб","существо","персонаж"}));
    SetAdjectives(({"крепко сложенный", "non player"}));
    SetShort("карлик");
    SetLong("Это типичный крепко сложенный карлик. С румяными щеками, большой бородой и за работой с металлом.");
    SetLevel(1);
    SetMelee(1);
    SetRace("dwarf");
    SetGender("male");
}
void init(){
    ::init();
}
