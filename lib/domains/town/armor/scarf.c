#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("шарф");
    SetId(({"шарф"}));
    SetAdjectives( ({"красивый","клетчатый"}) );
    SetShort("клетчатый шарф");
    SetLong("Это красивый клетчатый шарф ручной работы. "+
            "Вероятно, стоит он очень дорого.");
    SetMass(3);
    SetBaseCost("silver", 350);
    SetArmorType(A_COLLAR);
}

void init(){
    ::init();
}
