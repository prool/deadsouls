#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("додо");
    SetId(({"нпс","моб","существо","птица"}));
    SetAdjectives(({"толстый", "глупая"}));
    SetShort("толстый додо");
    SetLong("Это глупая небольшая птица обладает великолепным на вкус мясом.");
    SetWanderSpeed(10);
    SetLevel(1);
    SetMelee(1);
    SetRace("bird");
    SetMaxHealthPoints(30);
    SetGender("male");
}
void init(){
    ::init();
}
