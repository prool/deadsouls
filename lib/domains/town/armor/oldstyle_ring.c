#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("металлическое кольцо");
    SetId(({"кольцо"}));
    SetAdjectives( ({"простое","металлическое"}) );
    SetShort("простое кольцо");
    SetLong("Вы видите саоме обычное металлическое кольцо.");
    SetMass(1);
    SetValue(100);
    SetArmorType(A_RING);
}

void init(){
    ::init();
}
