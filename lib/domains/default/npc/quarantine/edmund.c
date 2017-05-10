#include <lib.h>

inherit LIB_NPC;


static void create() {
    npc::create();
    SetKeyName("Эдмунд");
    SetId(({"эдмунд"}));
    SetShort("Эдмунд");
    SetLong("Эдмунд - студент по программе обмена из Великобритании.");
    SetLevel(5);
    SetRace("human");
    SetGender("male");
    SetNoClean(1);
}
void init(){
    ::init();
}
