#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_WORN_STORAGE;

static void create(){
    ::create();
    SetKeyName("комбинезон");
    SetId(({"комбинезон","штаны", "trousers"}));
    SetAdjectives(({"широкие","abused","pair of","set of"}));
    SetShort("комбинезон");
    SetLong("Это широкие штаны на подтяжках с большим нагрудым карманом "
            "для инструментов.");
    SetMass(50);
    SetMaxCarry(300);
    SetBaseCost("silver",1);
    SetProtection(BLUNT,1);
    SetProtection(BLADE,1);
    SetProtection(KNIFE,1);
    SetArmorType(A_CUSTOM);
    SetRestrictLimbs( ({ "right leg","left leg","torso" }) );
}

void init(){
    ::init();
}
