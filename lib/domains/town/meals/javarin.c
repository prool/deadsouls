#include <lib.h>
#include ROOMS_H
#include <meal_types.h>
#include <vendor_types.h>

inherit LIB_POTION;

static void create() {
    ::create();
    SetKeyName("жаварин");
    SetId(({"пилюля","стимулянт"}));
    SetShort("пилюля жаварина");
    SetAdjectives(({"жаварин","небольшая","желтая"}));
    SetLong("Это небольшая желтая пилюля содержащая стимулянт.");
    SetMass(1);
    SetStrength(1);
    SetBaseCost("gold",1);
    SetStrength(1);
    SetMealType(MEAL_FOOD);
    SetMealMessages("Вы проглотили пилюлю.",
            "$N проглотил пилюлю.");
    SetDuration(10);
    SetStats( ([ "speed" : 1 ]) );
    SetPoints( ([ "caffeine" : 20 ]) );
    SetVendorType(VT_MAGIC);
}

void init(){
    ::init();
}
