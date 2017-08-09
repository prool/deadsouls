#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("защитный шлем");
    SetId(({"шлем","cover","motorcycle"}));
    SetAdjectives(({"черный","защитный","hard"}));
    SetShort("черный защитный шлем");
    SetLong("Этот шлем сделан из различных материалов для защиты головы на производстве.");
    SetMass(50);
    SetBaseCost("silver",200);
    SetArmorType(A_HELMET);
    SetProtection(BLUNT, 20);
    SetProtection(BLADE, 20);
    SetProtection(KNIFE, 20);
    SetProtection(PIERCE, 20);
}

void init(){
    ::init();
}
