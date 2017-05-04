#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
    item::create();
    SetKeyName("нож Пруля");
    SetId( ({ "knife2"}));
    SetAdjectives( ({ "prools","прулев"}));
    SetShort("нож Пруля");
    SetLong("нож со знаком Пруля");
    SetMagaral(1);
    SetMass(51);
    SetBaseCost("silver",6);
    SetVendorType(VT_WEAPON);
    SetClass(5);
    SetDamageType(KNIFE);
    SetWeaponType("knife");
}

void init(){
    ::init();
}
