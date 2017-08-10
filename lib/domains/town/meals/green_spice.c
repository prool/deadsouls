#include <lib.h>
#include ROOMS_H
#include <meal_types.h>
#include <vendor_types.h>

inherit LIB_POTION;

static void create() {
    ::create();
    SetKeyName("зеленая специя");
    SetId(({"специя","палочка","палочка зеленой специи","slender"}));
    SetShort("палочка зеленой специи");
    SetAdjectives(({"зеленой","зеленую"}));
    SetLong("Тонкая палочка зеленой специи.");
    SetMass(1);
    SetStrength(1);
    SetBaseCost("gold",12);
    SetStrength(1);
    SetMealType(MEAL_FOOD);
    SetMealMessages("Вы съели палочку зеленой специи.",
            "$N съел палочку зеленой специи.");
    SetDuration(60);
    SetStats( ([ "durability" : 1 ]) );
    SetPoints( ([ "HP" : 650 ]) );
    SetVendorType(VT_MAGIC);
}

void init(){
    ::init();
}
