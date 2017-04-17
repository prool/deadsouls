#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("ботинок для верховой езды");
    SetId(({"ботинок"}));
    SetAdjectives(({"длинный","верховой","правый","черный"}));
    SetShort("ботинок для верховой езды");
    SetLong("Это длинный ботинок для верховой езды, сделанный из черной кожи. "+
            "Одевается на правую ногу.");
    SetMass(60);
    SetBaseCost("silver",75);
    SetDamagePoints(5);
    SetProtection(BLUNT,5);
    SetProtection(BLADE,5);
    SetProtection(KNIFE,5);
    SetArmorType(A_LONG_BOOT);
    SetRestrictLimbs(({"right foot","right leg"}));
}
void init(){
    ::init();
}
