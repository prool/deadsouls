#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("ботинки для верховой езды");
    SetId(({"ботинки"}));
    SetAdjectives(({"длинные","верховой","черные"}));
    SetShort("ботинки для верховой езды");
    SetLong("Это длинные ботинки для верховой езды, сделанные из черной кожи.");
    SetMass(60);
    SetBaseCost("silver",75);
    SetDamagePoints(5);
    SetProtection(BLUNT,5);
    SetProtection(BLADE,5);
    SetProtection(KNIFE,5);
    SetArmorType(A_LONG_BOOT);
}

void init(){
    ::init();
}
