#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("пальто");
    SetId(({"пальто","overcoat"}));
    SetAdjectives(({"тяжелое","шерстяное"}));
    SetShort("тяжелое шерстяное пальто");
    SetLong("Это большое толстое пальто из медвежьей шкуры. Оно "+
            "защитит от самой сильной стужи.");
    SetMass(60);
    SetBaseCost("silver",300);
    SetProtection(BLUNT,10);
    SetProtection(BLADE,10);
    SetProtection(KNIFE,10);
    SetProtection(COLD,5);
    SetArmorType(A_CLOAK);
}

void init(){
    ::init();
}
