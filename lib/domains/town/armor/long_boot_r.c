#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("сапог для верховой езды");
    SetId(({"сапог"}));
    SetAdjectives(({"длинный","верховой","черный","leather","правый"}));
    SetShort("сапог для верховой езды");
    SetLong("Это сапог для верховой езды, сделанный из толстой черной кожи. Его "+
            "можно одеть на правую ступню и ногу.");
    SetMass(40);
    SetBaseCost("silver",75);
    SetProtection(BLUNT,5);
    SetProtection(BLADE,5);
    SetProtection(KNIFE,5);
    SetArmorType(A_LONG_BOOT);
    SetRestrictLimbs(({"right foot","right leg"}));
}

void init(){
    ::init();
}
