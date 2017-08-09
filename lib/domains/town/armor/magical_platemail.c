#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("латный доспех");
    SetId(({"доспех","латный доспех","platemail","suit","armor","suit of armor"}));
    SetAdjectives(({"полный","латный","plated","metal"}));
    SetShort("полный латный доспех");
    SetLong("Это большой и очень тяжелый доспех, который "+
            "только может одеть воин. Толстая "+
            "металлическая броня обеспечивает великолепную защиту, "+
            "а маслянная смазка сочленений практически не "+
            "стесняет свободы движения.");
    SetMass(900);
    SetBaseCost("silver",10000);
    SetDamagePoints(100);
    SetProtection(BLUNT,40);
    SetProtection(BLADE,60);
    SetProtection(KNIFE,60);
    SetProtection(PIERCE,60);
    SetArmorType(A_BODY_ARMOR);
}

void init(){
    ::init();
}
