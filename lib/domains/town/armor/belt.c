#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("ремень");
    SetId(({"кожаный ремень"}));
    SetAdjectives(({"кожаный"}));
    SetShort("кожаный ремень");
    SetLong("Самый обычный ремень из кожи.");
    SetMass(5);
    SetBaseCost("silver",10);
    SetProtection(BLUNT,1);
    SetProtection(BLADE,1);
    SetProtection(KNIFE,1);
    SetArmorType(A_BELT);
}

void init(){
    ::init();
}
