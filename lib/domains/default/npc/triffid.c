#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("триффид");
    SetAdjectives( ({"уродливое", "высокое"}) );
    SetId( ({"растение"}) );
    SetShort("высокое растение");
    SetLong("Это уродливое растение похоже на кукурузу-переросток. У него есть похожие на щупальца лианы, благодаря которым способно перемещаться.");
    SetLevel(1);
    SetMelee(1);
    SetRace("plant");
    SetGender("neuter");
}
void init(){
    ::init();
}
