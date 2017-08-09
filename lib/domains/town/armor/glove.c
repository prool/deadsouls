#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ARMOR;

static void create() {
    armor::create();
    SetKeyName("кожаные перчатки");
    SetId( ({ "перчатки" }) );
    SetAdjectives( ({ "черные","кожаные" }) );
    SetShort("черные кожаные перчатки");
    SetLong("Это самые обычные перчатки из тонкой черной кожи.");
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
    SetRestrictLimbs(({"right hand"}));
}

void init(){
    ::init();
}
