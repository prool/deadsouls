#include <lib.h>
#include <vendor_types.h>
#include <meal_types.h>

inherit LIB_POTION;

static void create() {
    potion::create();
    SetKeyName("противоядие");
    SetId( ({ "склянка","bottle", "противоядие","philtrum","antidote to poison","vial of antidote" }) );
    SetAdjectives( "небольшая" );
    SetShort("склянка с противоядием");
    SetLong("Небольшая склянка с синей жидкостью, нейтрализующей действие яда.");
    SetMass(20);
    SetMealType(MEAL_DRINK);
    SetStrength(5);
    SetMealMessages("вы выпили из склянки.",
            "$N выпил из склянки.");
    SetBaseCost("silver",200);
    SetPoints( ([ "poison" : -10 ]) );
    SetEmptyName("склянка");
    SetEmptyShort("пустая склянка");
    SetEmptyLong("Это пустая маленькая склянка.");
    SetVendorType(VT_TREASURE);
}
void init(){
    ::init();
}
