#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("орочий сапог");
    SetAdjectives( ({"кожаный", "простой", "orc", "орочий", "некрасивый", "левый"}) );
    SetId(({"сапог","левый сапог"}));
    SetShort("орочий сапог");
    SetLong("Это кожаный сапог работы орков. Он простой и некрасивый, но дает хорошую защиту. Его можно одеть на левую ногу.");
    SetMass(60);
    SetBaseCost("silver", 30);
    SetProtection(BLUNT,5);
    SetProtection(BLADE,5);
    SetProtection(KNIFE,5);
    SetArmorType(A_BOOT);
    SetRestrictLimbs(({"left foot"}));
}

void init(){
    ::init();
}
