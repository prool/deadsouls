#include <lib.h>
#include ROOMS_H
#include <meal_types.h>
#include <vendor_types.h>

inherit LIB_POTION;

static void create() {
    ::create();
    SetKeyName("спидалин");
    SetId(({"пилюля","stimulant"}));
    SetShort("пилюля спидалина");
    SetAdjectives(({"спидалин","маленькая","белая"}));
    SetLong("Маленькая белая пилюля содержащая спидалин.");
    SetMass(1);
    SetStrength(1);
    SetBaseCost("gold",2);
    SetStrength(1);
    SetMealType(MEAL_FOOD);
    SetMealMessages("Вы проглотили пилюлю.",
            "$N проглотил пилюлю.");
    SetDuration(20);
    SetStats( ([ "speed" : 1 ]) );
    SetPoints( ([ "caffeine" : 30 ]) );
    SetVendorType(VT_MAGIC);
}

void init(){
    ::init();
}
