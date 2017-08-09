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
    SetMass(1000);
    SetBaseCost("silver",10000);
    SetProtection(BLUNT,60);
    SetProtection(BLADE,90);
    SetProtection(KNIFE,90);
    SetArmorType(A_BODY_ARMOR);
}

void init(){
    ::init();
}
