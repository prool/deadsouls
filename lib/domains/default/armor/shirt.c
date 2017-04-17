#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;
static void create(){
    armor::create();
    SetKeyName("белая рубаха");
    SetId(({"рубаха"}));
    SetAdjectives(({"белая","обычная"}));
    SetShort("белая рубаха");
    SetLong("Самая обычная белая рубаха.");
    SetMass(5);
    SetBaseCost(1);
    SetDamagePoints(1);
    SetProtection(BLUNT,1);
    SetProtection(BLADE,1);
    SetProtection(KNIFE,1);
    SetArmorType(A_SHIRT);
}
