#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("очки");
    SetId(({"очки"}));
    SetAdjectives(({"clear","plastic","protective","lab","лабораторные"}));
    SetShort("очки");
    SetLong("Такие очки носят стремящиеся выглядеть умнее ученые.");
    SetMass(5);
    SetBaseCost("silver",9);
    SetDamagePoints(1);
    SetProtection(BLUNT,1);
    SetProtection(BLADE,1);
    SetProtection(KNIFE,1);
    SetArmorType(A_VISOR);
}

void init(){
    ::init();
}
