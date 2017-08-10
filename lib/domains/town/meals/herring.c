#include <lib.h>
#include <meal_types.h>
#include <dirs.h>

inherit LIB_FISH;

static void create() {
    fish::create();
    SetKeyName("селедка");
    SetId( ({ "рыба" }) );
    SetAdjectives( ({ "красная","saltwater","salt water" }) );
    SetShort("красная селедка");
    SetLong("Это морская рыба красного цвета");
    SetMealType(MEAL_FOOD);
    SetMass(10); 
    SetStrength(10); 
    SetBaseCost("silver", 2);
    SetFight(4);
    SetFood("/domains/town/meals/herring");
}
void init(){
    ::init();
}
