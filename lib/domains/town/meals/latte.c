#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;


static void create()  {
    meal::create();
    SetKeyName("латте");
    SetId("латте");
    SetShort("кофе латте");
    SetLong("Великолепный кофейный напиток с большим содержанием молока, "
            "невероятно вкусно!");
    SetMass(10);
    SetMealType( MEAL_DRINK | MEAL_CAFFEINE );
    SetStrength(25);
    SetValue(2);
    SetMealMessages("Вы выпили кофе латте." , 
            "$N выпил $P кофе латте.");
}
void init(){
    ::init();
}
