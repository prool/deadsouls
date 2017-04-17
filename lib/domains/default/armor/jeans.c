#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;
static void create(){
    armor::create();
    SetKeyName("дырявые штаны");
    SetId(({"штаны","синие","синие штаны","дырявые штаны","дырявые"}));
    SetAdjectives(({"синие","дырявые"}));
    SetShort("синие дырявые штаны");
    SetLong("Старые дырявые штаны, налетающие порывы ветра свободно гуляют в них.");
    SetMass(5);
    SetBaseCost(1);
    SetDamagePoints(1);
    SetProtection(BLUNT,1);
    SetProtection(BLADE,1);
    SetProtection(KNIFE,1);
    SetArmorType(A_PANTS);
}
