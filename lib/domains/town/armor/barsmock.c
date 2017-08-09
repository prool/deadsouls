#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("халат");
    SetAdjectives( ({"обычный","белый"}) );
    SetId( ({"халат", "smock", "simple"}) );
    SetShort("обычный халат");
    SetLong("Это обычный белый халат, такие носят обычно работники пищевой промышленности.");
    SetMass(50);
    SetArmorType(A_BODY_ARMOR);
}

void init(){
    ::init();
}
