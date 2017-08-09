#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("кожаный жилет");
    SetAdjectives( ({"жилет", "кожаный", "sturdy", "protective"}) );
    SetId(({"жилет"}));
    SetShort("кожаный жилет");
    SetLong("Прочный кожаный жилет, который обеспечивает защиту от повреждений и холода для туловища, не стесняя при этом движения рук.");
    SetMass(50);
    SetBaseCost("silver", 100);
    SetArmorType(A_VEST);
    SetProtection(COLD, 10);
    SetProtection(BLUNT, 1);
    SetProtection(BLADE, 5);
    SetProtection(KNIFE, 5);
}

void init(){
    ::init();
}
