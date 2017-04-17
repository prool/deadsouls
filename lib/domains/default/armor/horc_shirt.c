#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("рубаха");
    SetAdjectives( ({"дырявая"}) );
    SetId( ({"рубаха", "дырявая"}) );
    SetShort("дырявая рубаха");
    SetLong("Самая обычная рубаха с несколькими дырами, сквозь которые проглядывает тело.");
    SetMass(50);
    SetDamagePoints(100);
    SetArmorType(A_SHIRT);
    SetProtection(BLUNT, 20);
    SetProtection(BLADE, 20);
    SetProtection(KNIFE, 20);
}
void init(){
    ::init();
}
