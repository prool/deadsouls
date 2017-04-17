#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("кожаные штаны");
    SetId(({"штаны"}));
    SetAdjectives(({"прочные","кожаные"}));
    SetShort("кожаные штаны");
    SetLong("Эти штаны сделаны из прочной кожи и защищают ноги от случайных порезов или ударов. ");
    SetMass(150);
    SetBaseCost("silver",110);
    SetDamagePoints(10);
    SetProtection(BLUNT,1);
    SetProtection(BLADE,5);
    SetProtection(KNIFE,5);
    SetArmorType(A_PANTS);
}
void init(){
    ::init();
}
