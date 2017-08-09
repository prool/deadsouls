#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("сапоги для верховой езды");
    SetId(({"сапоги"}));
    SetAdjectives(({"длинные","riding","черные","кожаные"}));
    SetShort("сапоги для верховой езды");
    SetLong("Это длинные сапоги из черной кожи, предназначенные для верховой езды.");
    SetMass(30);
    SetBaseCost("silver",75);
    SetProtection(BLUNT,5);
    SetProtection(BLADE,5);
    SetProtection(KNIFE,5);
    SetArmorType(A_BOOT);
}

void init(){
    ::init();
}
