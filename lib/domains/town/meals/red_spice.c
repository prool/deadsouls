#include <lib.h>
#include ROOMS_H
#include <meal_types.h>
#include <vendor_types.h>

inherit LIB_POTION;

static void create() {
    ::create();
    SetKeyName("красная специя");
    SetId(({"специя","палочка","палочка красной специи","slender"}));
    SetShort("палочка красной специи");
    SetAdjectives(({"красной","красную"}));
    SetLong("Тонкая палочка красной специи.");
    SetMass(1);
    SetStrength(1);
    SetBaseCost("gold",8);
    SetStrength(1);
    SetMealType(MEAL_FOOD);
    SetMealMessages("Вы съели палочку красной специи.",
            "$N съел палочку красной специи.");
    SetDuration(1);
    SetPoints( ([ "HP" : 300 ]) );
    SetVendorType(VT_MAGIC);
}

void init(){
    ::init();
}
