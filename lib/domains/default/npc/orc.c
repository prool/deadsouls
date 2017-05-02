#include <lib.h>

inherit LIB_NPC;

static void create() {
    npc::create();
    SetKeyName("орк");
    SetId(({"орк"}));
    SetAdjectives(({"грязный"}));
    SetShort("грязный орк");
    SetLong("Это типичный орк во всей его красе: грязный, вонючий и уродливый. Кажется, "
            "что он еще довольно молод и это делает его менее "
            "опасным, но более враждебным. ");
    SetLevel(1);
    SetRace("orc");
    SetGender("male");
    SetMaxHealthPoints(100);
    SetEncounter(0);
    SetInventory(([
                "/domains/default/weap/axe":"wield axe",
                ]) );

}
void init(){
    ::init();
}
