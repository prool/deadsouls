#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("черная футболка");
    SetId(({"футболка","def leppard shirt"}));
    SetAdjectives(({"Def Leppard", "def leppard", "stupid", "черная"}));
    SetShort("черная футболка");
    SetLong("Вы видите немного глуповатую черную футболку с пиратской эмблемой на груди.");
    SetMass(5);
    SetBaseCost("silver",1);
    SetProtection(BLUNT,1);
    SetProtection(BLADE,1);
    SetProtection(KNIFE,1);
    SetArmorType(A_SHIRT);
    //SetRestrictLimbs(({"torso"}));
}

void init(){
    ::init();
}
