#include <lib.h>
#include <vendor_types.h>
#include <meal_types.h>

inherit LIB_POTION;

static void create() {
    potion::create();
    SetKeyName("зелье");
    SetId( ({ "бутылка", "зелье","бутылочка","зелье лечения","зелье слабого лечения" }) );
    SetAdjectives(({"зеленое", "слабого", "greater healing"}));
    SetShort("зеленое зелье слабого лечения");
    SetLong("Это небольшая бутылочка с зеленой жидкостью, которая способна залечивать зарапины.");
    SetMass(60);
    SetMealType(MEAL_DRINK);
    SetStrength(5);
    SetMealMessages("Вы выпили зелье.",
            "$N выпил зелье.");
    SetBaseCost("silver",500);
    SetPoints( ([ "HP" : 100 ]) );
    SetVendorType(VT_MAGIC);
}
void init(){
    ::init();
}
