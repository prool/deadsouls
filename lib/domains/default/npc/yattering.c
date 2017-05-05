#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("ятеринг");
    SetId(({"нпс","моб","монстр","ятеринг"}));
    SetAdjectives(({"глупый", "маленький"}));
    SetShort("глупый маленький ятеринг");
    SetLong("Это невысокое мясистое существо с недоразвитыми крыльями на спине. Как бы нелепо оно не выглядело, его черные когти и клюв остры и опасны.");
    SetClass("fighter");
    SetLevel(5);
    SetMelee(1);
    SetRace("demon");
    SetGender("male");
}
void init(){
    ::init();
}
