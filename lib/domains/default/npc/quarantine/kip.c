#include <lib.h>

inherit LIB_NPC;

static void create() {
    npc::create();
    SetKeyName("Кип");
    SetId(({"кип"}));
    SetShort("Кип");
    SetLong("Кип - студент по программе обмена из Нидерландов.");
    SetMelee(1);
    SetLevel(5);
    SetRace("human");
    SetGender("male");
    SetNoClean(1);
}
void init(){
    ::init();
}
