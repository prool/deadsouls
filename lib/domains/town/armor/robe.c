#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("мантия волшебника");
    SetId(({"мантия","cloak","duster"}));
    SetAdjectives(({"удобная","wizard's","широкая"}));
    SetShort("мантия");
    SetLong("Такие широкие удобные мантии часто любят носить странствующие волшебники. ");
    SetMass(200);
    SetBaseCost("silver",100);
    SetProtection(BLUNT,100);
    SetProtection(BLADE,100);
    SetProtection(KNIFE,100);
    SetArmorType(A_CLOAK);
}

void init(){
    ::init();
}
