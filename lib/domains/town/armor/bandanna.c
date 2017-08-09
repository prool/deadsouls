#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("бандана");
    SetAdjectives( ({"красная"}) );
    SetId( ({"бандана", "красная повязка"}) );
    SetShort("красная бандана");
    SetLong("Из этого красного платка соорудили импровизированный головной убор, вероятно чтобы уберечь волосы от грязи и палящего солнца.");
    SetMass(1);
    SetBaseCost("silver",1);
    SetArmorType(A_HELMET);
    SetProtection(BLUNT, 1);
    SetProtection(BLADE, 1);
    SetProtection(KNIFE, 1);
}

void init(){
    ::init();
}
