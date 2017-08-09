#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("полотенце");
    SetId(({"полотенце"}));
    SetAdjectives(({"влажное","bath","ordinary", "bathtowel"}));
    SetShort("влажное полотенце");
    SetLong("Это самое обычное полотенце, такие носят обычно после бани или сауны.");
    SetMass(25);
    SetBaseCost("silver",10);
    SetProtection(BLUNT,1);
    SetProtection(BLADE,1);
    SetProtection(KNIFE,1);
    SetArmorType(A_PANTS);
}

void init(){
    ::init();
}
