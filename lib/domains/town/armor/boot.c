#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("кажаные ботинки");
    SetId(({"ботинки"}));
    SetAdjectives(({"военные","military-style","черные","кожаные","боевые"}));
    SetShort("черные кожаные ботинки");
    SetLong("Вы видите ботинки в военном стиле, сделанные из черной кожи.");
    SetMass(20);
    SetBaseCost("silver",25);
    SetProtection(BLUNT,5);
    SetProtection(BLADE,5);
    SetProtection(KNIFE,5);
    SetArmorType(A_BOOT);
}

void init(){
    ::init();
}
