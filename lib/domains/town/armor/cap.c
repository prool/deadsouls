#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("кепка");
    SetAdjectives( ({"красная", "старая", "пыльная", "грязная", "baseball", "cat"}) );
    SetId( ({"cap", "hat", "cover"}) );
    SetShort("красная кепка");
    SetLong("Вы видите старую грязную кепку красного цвета с непонятной "
            "надписью над козырьком.");
    SetMass(5);
    SetBaseCost("silver",1);
    SetArmorType(A_HELMET);
}

void init(){
    ::init();
}
