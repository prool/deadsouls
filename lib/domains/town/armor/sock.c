#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("носок");
    SetId(({"носок"}));
    SetAdjectives(({"белый","хлопковый","athletic"}));
    SetShort("белый хлопковый носок");
    SetLong("Такие носки из белого хлопка носят обычно тренирующиеся спортсмены.");
    SetMass(5);
    SetBaseCost("silver",1);
    SetArmorType(A_SOCK);
}

void init(){
    ::init();
}
