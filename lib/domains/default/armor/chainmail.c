#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("кольчужная рубашка");
    SetId(({"доспех","колучужная рубашка","кольчуга","рубашка"}));
    SetAdjectives(({"кольчужная","sturdy","sturdy-looking","chain mail"}));
    SetShort("кольчужная рубашка");
    SetLong("Кольчуга сплетенная из серебряных колец в полный человеческий рост.");
    SetMass(600);
    SetBaseCost("silver",1000);
    SetDamagePoints(100);
    SetProtection(BLUNT,4);
    SetProtection(BLADE,25);
    SetProtection(KNIFE,25);
    SetArmorType(A_ARMOR);
}
void init(){
    ::init();
}
