#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;
static void create(){
    armor::create();
    SetKeyName("влажное полотенце");
    SetId(({"полотенце"}));
    SetAdjectives(({"влажное","банное","обычное"}));
    SetShort("влажное полотенце");
    SetLong("Это самое обычное банное полотенце.");
    SetMass(25);
    SetDamagePoints(10);
    SetProtection(BLUNT,1);
    SetProtection(BLADE,1);
    SetProtection(KNIFE,1);
    SetArmorType(A_PANTS);
}
