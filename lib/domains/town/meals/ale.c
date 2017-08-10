#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;


static void create() {
    meal::create();
    SetKeyName("эль");
    SetId( ({ "бутылка", "эль", "первоклассный эль", "великолепный" }) );
    SetShort("бутылка эля");
    SetLong("Это бутылка великолепного эля.");
    SetMass(60);
    SetMealType(MEAL_DRINK | MEAL_ALCOHOL);
    SetStrength(5);
    SetMealMessages("Вы выпили бутылку эля.",
            "$N выпил бутылку эля.");
    SetBaseCost("silver",10);
}
void init(){
    ::init();
}
