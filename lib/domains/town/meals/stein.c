#include <lib.h>
#include <vendor_types.h>
#include <meal_types.h>
inherit LIB_FLASK;

void create(){
    ::create();
    SetKeyName("пиво");
    SetId( ({"бутыль","бутылка","guinness"}) );
    SetAdjectives( ({"большая","пиво","guinness"}) );
    SetShort("большая бутылка пива");
    SetLong("Большая полупрозрачная бутыль с полуторами литрами живительной жидкости.");
    SetMass(40);
    SetBaseCost("gold",1);
    SetVendorType(VT_DRINK);
    SetFlaskContents("Guinness");
    SetFlaskUses(10);
    SetStrength(10);
    SetMaxFlask(10); 
    SetMealType(MEAL_ALCOHOL|MEAL_DRINK);
}
void init(){
    ::init();
}
