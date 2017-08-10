#include <lib.h>
#include <vendor_types.h>
#include <meal_types.h>

inherit LIB_POTION;

static void create() {
    potion::create();
    SetKeyName("зелье");
    SetId( ({ "бутылка", "зелье","бутылочка","зелье лечения","зелье серьезного лечения" }) );
    SetAdjectives(({"зеленое", "серьезного", "greater healing"}));
    SetShort("зеленое зелье серьезного лечения");
    SetLong("Это небольшая бутылочка с зеленой жидкостью, которая способна залечивать раны.");
    SetMass(60);
    SetMealType(MEAL_DRINK);
    SetStrength(15);
    SetMealMessages("Вы выпили зелье.",
            "$N выпил зелье.");
    SetBaseCost("silver",5500);
    SetPoints( ([ "HP" : 1000 ]) );
    SetVendorType(VT_MAGIC);
}
void init(){
    ::init();
}
