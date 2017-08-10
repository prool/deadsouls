#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;


static void create() {
    meal::create();
    SetKeyName("бурбон");
    SetAdjectives( ({ "dark","green","дешевый","бурбон" }) );
    SetId( ({ "бутылка", "бутылка бурбона" }) );
    SetShort("бутылка бурбона");
    SetLong("Это бутылка из темного зеленого стекла с дешевым бурбоном.");
    SetMass(100);
    SetBaseCost("silver",20);
    SetMealType(MEAL_DRINK | MEAL_ALCOHOL);
    SetStrength(30);
    SetMealMessages("Вы опустошаете бутылку бурбона!",
            "$N опустошает бутылку бурбона!");
}
void init(){
    ::init();
}
