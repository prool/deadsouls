#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ARMOR;

static void create() {
    armor::create();
    SetKeyName("большой щит");
    SetId( ({ "щит" }) );
    SetAdjectives( ({ "деревянный", "wooden","большой" }) );
    SetShort("большой деревянный щит");
    SetLong("Это большой деревянный щит, для прочности обитый листами железа.");
    SetVendorType(VT_ARMOR);
    SetMass(100);
    SetBaseCost("silver",250);
    SetArmorType(A_SHIELD);
    SetProtection(BLUNT, 10);
    SetProtection(BLADE, 10);
    SetProtection(KNIFE, 10);
    //SetRestrictLimbs( ({"left hand"}) );
}

void init(){
    ::init();
}
