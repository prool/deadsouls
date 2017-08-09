#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("кожаные штаны");
    SetId(({"штаны"}));
    SetAdjectives(({"прочные","кожаные","черные","tough"}));
    SetShort("кожаные штаны");
    SetLong("Эти штаны сделаны из прочной черной кожи. ");
    SetMass(150);
    SetBaseCost("silver",110);
    SetProtection(BLADE,10);
    SetProtection(KNIFE,10);
    SetArmorType(A_PANTS);
}

void init(){
    ::init();
}
