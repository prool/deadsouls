#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("футболка");
    SetAdjectives( ({"horse", "t", "обычная", "хлопковая"}) );
    SetId( ({"футболка", "t-shirt"}) );
    SetShort("футболка");
    SetLong("Это самая обычная футболка из хлопка с надписью: 'Я маленькая лошадка!'");
    SetMass(5);
    SetBaseCost("silver",1);
    SetArmorType(A_SHIRT);
}

void init(){
    ::init();
}
