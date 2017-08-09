#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("кольчужная рубашка");
    SetId(({"доспех","кольчуга","рубашка","кольчужная","кольчужная рубашка"}));
    SetAdjectives(({"кольчужная","прочная","sturdy-looking","chain mail"}));
    SetShort("прочная кольчужная рубашка");
    SetLong("Эта рубашка сделана из крепких металлических колец, скрепленных вместе.");
    SetMass(200);
    SetBaseCost("silver",800);
    SetProtection(BLUNT,5);
    SetProtection(BLADE,20);
    SetProtection(KNIFE,20);
    SetArmorType(A_ARMOR);
}

void init(){
    ::init();
}
