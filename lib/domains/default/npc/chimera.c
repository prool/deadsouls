#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("химера");
    SetId(({"нпс","моб","существо","монстр"}));
    SetAdjectives(({"ужасная", "ужасный"}));
    SetShort("ужасная химера");
    SetLong("Этот ужасный монстр состоит из частей различных животных. Тело и одна голова у химеры львиные, вторая голова от дракона, а третья козья. Дополняет это ужасное зрелище отвратительный змеиный хвост.");
    SetClass("fighter");
    SetLevel(15);
    SetMelee(1);
    SetRace("chimera");
    SetGender("male");
}
void init(){
    ::init();
}
