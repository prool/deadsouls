#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;


static void create()  {
    meal::create();
    SetKeyName("вода");
    SetId(({ "бутылка","вода"}));
    SetAdjectives(({"чистая","родниковая"}));
    SetShort("бутылка воды");
    SetLong("Это бутылка с чистой родниковой водой.");
    SetMass(10);
    SetMealType(MEAL_DRINK);
    SetStrength(10);
    SetBaseCost("silver",2);
    SetMealMessages("Вы пьете воду и чувствуете себя посвежевшим.", "$N пьет "+
            "$P воду.");
}
void init(){
    ::init();
}
