#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;


static void create() {
    meal::create();
    SetKeyName("огненный бурбон");
    SetId( ({ "бутылка", "бурбон" ,"fire","огненный",
                "бутылка бурбона"}) );
    SetAdjectives( ({ "firebreather","dark","green","bourbon"}) );
    SetShort("бутылка бурбона");
    SetLong("Это бутылка из темного зеленого стекла с бурбоном марки 'огненный'.");
    SetMass(100);
    SetBaseCost("silver",50);
    SetMealType(MEAL_DRINK | MEAL_ALCOHOL);
    SetStrength(40);
    SetMealMessages("Вы опустошаете бутылку бурбона!",
            "$N опустошает бутылку бурбона!");
}

void init(){
    ::init();
}
