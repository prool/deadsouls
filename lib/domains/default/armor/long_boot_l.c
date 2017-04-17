#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("ботинок для верховой езды");
    SetId(({"ботинок"}));
    SetAdjectives(({"длинный","верховой","левый","черный"}));
    SetShort("ботинок для верховой езды");
    SetLong("Это длинный ботинок для верховой езды, сделанный из черной кожи. "+
            "Одевается на левую ногу.");
    SetMass(60);
    SetBaseCost("silver",75);
    SetDamagePoints(5);
    SetProtection(BLUNT,5);
    SetProtection(BLADE,5);
    SetProtection(KNIFE,5);
    SetArmorType(A_LONG_BOOT);
    SetRestrictLimbs(({"left foot","left leg"}));
}
void init(){
    ::init();
}
