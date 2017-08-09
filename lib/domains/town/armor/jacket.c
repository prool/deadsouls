#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("кожаный жакет");
    SetId(({"жакет"}));
    SetAdjectives(({"черный","кожаный"}));
    SetShort("черный кожаный жакет");
    SetLong("Это самый обычный жакет, сделанный из тонкой черной кожи. ");
    SetMass(50);
    SetBaseCost("silver",100);
    SetProtection(BLUNT,1);
    SetProtection(BLADE,2);
    SetProtection(KNIFE,5);
    SetArmorType(A_ARMOR);
}

void init(){
    ::init();
}
