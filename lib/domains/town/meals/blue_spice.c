#include <lib.h>
#include ROOMS_H
#include <meal_types.h>
#include <vendor_types.h>

inherit LIB_POTION;

static void create() {
    ::create();
    SetKeyName("синяя специя");
    SetId(({"специя","палочка","палочка синей специи","slender"}));
    SetShort("палочка синей специи");
    SetAdjectives(({"синей","синюю"}));
    SetLong("Тонкая палочка синей специи.");
    SetMass(1);
    SetStrength(1);
    SetBaseCost("gold",10);
    SetStrength(1);
    SetMealType(MEAL_FOOD);
    SetMealMessages("Вы съели палочку синей специи.",
            "$N съел палочку синей специи.");
    SetDuration(30);
    SetStats( ([ "durability" : 1 ]) );
    SetPoints( ([ "HP" : 450 ]) );
    SetVendorType(VT_MAGIC);
}

void init(){
    ::init();
}
