#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;


static void create() {
    meal::create();
    SetKeyName("бутерброд");
    SetId(({"бутерброд","ham sandwich"}));
    SetShort("бутерброд с ветчиной");
    SetLong("Это большой сочный бутерброд с ветчиной.");
    SetMass(10);
    SetStrength(20);
    SetBaseCost("silver",10);
    SetMealType(MEAL_FOOD);
    SetMealMessages("Вы съели бутерброд с ветчиной. Вкусно!",
            "$N съел $P бутерброд с ветчиной.");
}
void init(){
    ::init();
}
