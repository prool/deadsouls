#include <lib.h>
#include ROOMS_H
#include <meal_types.h>
#include <vendor_types.h>

inherit LIB_POTION;

static void create() {
    ::create();
    SetKeyName("спазалин");
    SetId(({"пилюля","stimulant"}));
    SetShort("пилюля спазалина");
    SetAdjectives(({"спазалин","маленькая","красная"}));
    SetLong("Маленькая красная пилюля содержащая спазалин.");
    SetMass(1);
    SetStrength(1);
    SetBaseCost("gold",3);
    SetStrength(1);
    SetMealType(MEAL_FOOD);
    SetMealMessages("Вы проглотили пилюлю.",
            "$N проглотил пилюлю.");
    SetDuration(60);
    SetStats( ([ "speed" : 1 ]) );
    SetPoints( ([ "caffeine" : 40 ]) );
    SetVendorType(VT_MAGIC);
}

void init(){
    ::init();
}
