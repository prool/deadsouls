#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("синие штаны");
    SetId(({"jeans","штаны","синие штаны","bluejeans","denim"}));
    SetAdjectives(({"синие","denim","удобные","broken in","broken-in"}));
    SetShort("синие штаны");
    SetLong("Это удобные синие штаны из прочной ткани.");
    SetMass(20);
    SetBaseCost("silver",1);
    SetArmorType(A_PANTS);
}

void init(){
    ::init();
}
