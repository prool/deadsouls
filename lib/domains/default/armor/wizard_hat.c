#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("шляпа волшебника");
    SetAdjectives( ({"волшебника","wizards", "floppy", "large", "conical", "blue"}) );
    SetId( ({"шляпа"}) );
    SetShort("шляпа волшебника");
    SetLong("Это большая гибкая шляпа с широкими полями "+
            "и конической основой. Она темно-синего цвета "+
            "и украшена золотыми узорами в виде звезд и полумесяцев.");
    SetProperties(([
                "beta" : 2,
                ]));
    SetMass(50);
    SetBaseCost("silver",500);
    SetDamagePoints(100);
    SetArmorType(A_HELMET);
    SetProtection(BLUNT, 20);
    SetProtection(BLADE, 20);
    SetProtection(KNIFE, 20);
}
void init(){
    ::init();
}
