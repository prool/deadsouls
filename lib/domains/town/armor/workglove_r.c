#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ARMOR;

static void create() {
    armor::create();
    SetKeyName("рабочая перчатка");
    SetAdjectives( ({"рабочая", "коричневая", "кожаная", "правая"}) );
    SetId( ({ "перчатка" }) );
    SetShort("кожаная рабочая перчатка");
    SetLong("Вы видите перчатку из толстой коричневой кожи, предназначенную для работы. Ее можно одеть на правую руку.");
    SetVendorType(VT_ARMOR);
    SetMass(10);
    SetBaseCost("silver",7);
    SetArmorType(A_GLOVE);
    SetProtection(BLUNT, 1);
    SetProtection(BLADE, 1);
    SetProtection(KNIFE, 2);
    SetProtection(HEAT, 3);
    SetProtection(COLD, 7);
    SetFingers(5);
    SetRestrictLimbs(({"right hand"}));
}

void init(){
    ::init();
}
