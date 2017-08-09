#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("чулки");
    SetId(({"чулки"}));
    SetAdjectives(({"черные","nylon","длинные","knee","knee length"}));
    SetShort("длинные черные чулки");
    SetLong("Это пара длинных черных чулков, очень эротичных.");
    SetMass(5);
    SetBaseCost("silver",1);
    SetProtection(BLUNT,1);
    SetProtection(BLADE,1);
    SetProtection(KNIFE,1);
    SetArmorType(A_LONG_SOCK);
}

void init(){
    ::init();
}
