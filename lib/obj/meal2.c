#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;


static void create() {
    meal::create();
    SetKeyName("еда");
    SetId(({"еда","рацион"}));
    SetShort("рацион мадера");
    SetLong("Это обычная еда");
    SetMass(10);
    SetStrength(20);
    SetBaseCost("silver",10);
    SetMealType(MEAL_FOOD);
    SetMealMessages("Вы съели еду",
            "$N съел $P еду.");
    SetNoCondition(1);
}
void init(){
    ::init();
}
