#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("белая футболка");
    SetId(({"футболка","tshirt","t-shirt","t shirt"}));
    SetAdjectives(({"белая"}));
    SetShort("белая футболка");
    SetLong("Это самая обычная белая футболка.");
    SetMass(2);
    SetBaseCost("silver",1);
    SetArmorType(A_SHIRT);
}

void init(){
    ::init();
}
