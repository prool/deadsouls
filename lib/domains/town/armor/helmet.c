#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("стальной шлем");
    SetId(({"шлем","cover","стальной"}));
    SetAdjectives(({"боевой","металлический","прочный"}));
    SetShort("стальной шлем");
    SetLong("Этот шлем сделан из толстой прочной стали, он отлично защищает голову.");
    SetMass(200);
    SetBaseCost("silver",500);
    SetArmorType(A_HELMET);
    SetProtection(BLUNT, 20);
    SetProtection(BLADE, 20);
    SetProtection(KNIFE, 20);
}

void init(){
    ::init();
}
