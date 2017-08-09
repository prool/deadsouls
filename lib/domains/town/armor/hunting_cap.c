#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("охотничья шапка");
    SetId(({"шапка","headgear","cap"}));
    SetAdjectives(({"мягкая","войлочная","охотничья"}));
    SetShort("охотничья шапка");
    SetLong("Это мягкая, войлочная шапка, которую можно носить при охоте. "+
            "У нее есть также одно перо, непринужденно застрявшее в стороне.");
    SetMass(10);
    SetBaseCost("silver",50);
    SetDamagePoints(10);
    SetArmorType(A_HELMET);
    SetProtection(BLUNT, 1);
    SetProtection(BLADE, 1);
    SetProtection(KNIFE, 1);
    SetItems( ([
                ({"pheasant","перо"})  : "Похоже на перо фазана.",
                ]) );
}

void init(){
    ::init();
}
