#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ARMOR;

static void create() {
    armor::create();
    SetKeyName("черная перчатка");
    SetId( ({ "перчатка" }) );
    SetAdjectives( ({ "черная","кожаная","левая" }) );
    SetShort("черная кожаная перчатка");
    SetLong("Это самая обычная перчатка из тонкой черной кожи, ее можно одеть на левую руку.");
    SetVendorType(VT_ARMOR);
    SetMass(5);
    SetBaseCost("silver",7);
    SetArmorType(A_GLOVE);
    SetProtection(BLUNT, 1);
    SetProtection(BLADE, 1);
    SetProtection(KNIFE, 2);
    SetProtection(HEAT, 3);
    SetProtection(COLD, 7);
    SetFingers(5);
    SetRestrictLimbs(({"left hand"}));
}

void init(){
    ::init();
}
