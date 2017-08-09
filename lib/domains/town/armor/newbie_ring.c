#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("золотое кольцо");
    SetId(({"кольцо","золотое кольцо"}));
    SetAdjectives( ({"красивое"}) );
    SetShort("красивое золотое кольцо");
    SetLong("Это простое, но красивое кольцо сделано из "+
            "первоклассного золота. Его можно одеть на палец.");
    SetMass(1);
    SetBaseCost("silver",500);
    SetArmorType(A_RING);
}

void init(){
    ::init();
}
