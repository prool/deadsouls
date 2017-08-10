#include <lib.h>
#include <vendor_types.h>
#include <meal_types.h>

inherit LIB_POTION;

static void create() {
    potion::create();
    SetKeyName("зелье");
    SetId( ({ "бутылочка", "зелье", "philtrum", "зелье силы" }) );
    SetAdjectives( "красное", "strength", "strongitude", "strongicity" );
    SetShort("красное зелье силы");
    SetLong("Это небольшая бутылочка с красной жидкостью, которая способна сделать вас сильнее.");
    SetMass(60);
    SetMealType(MEAL_DRINK);
    SetStrength(5);
    SetMealMessages("Вы выпили зелье.",
            "$N выпил зелье.");
    SetBaseCost("silver",1000);
    SetDuration(300);
    SetStats( ([ "strength" : 10 ]) );
    SetPoints( ([ "HP" : 50, "SP" : 50 ]) );
    SetVendorType(VT_MAGIC);
}
void init(){
    ::init();
}
