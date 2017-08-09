#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("шляпа волшебника");
    SetId(({"шляпа","волшебника"}));
    SetAdjectives(({"wizard","wizard's"}));
    SetShort("шляпа волшебника");
    SetLong("Это большая широкополая шляпа с высоким коническим основанием. "+
            "Она темно синего цвета и украшена вышивками "+
            "полумесяцев и звезд.");
    SetMass(50);
    SetBaseCost("silver",500);
    SetArmorType(A_HELMET);
    SetProtection(BLUNT, 20);
    SetProtection(BLADE, 20);
    SetProtection(KNIFE, 20);
}

void init(){
    ::init();
}
