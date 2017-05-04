#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("пессис");
    SetId( ({"полуорк", "полу орк", "полу человек", "получеловек"}) );
    SetAdjectives(({"non-player", "non player"}));
    SetShort("Пессис-полуорк");
    SetLong("Пессис слишком дик для человека и слишком нежен для орка. Его везде отвергают и отовсюду прогоняют.");
    SetInventory(([
                "/domains/default/armor/horc_shirt" : "wear tshirt",
                ]));
    SetLevel(1);
    SetMelee(1);
    SetRace("half-orc");
    SetGender("male");
}
void init(){
    ::init();
}
