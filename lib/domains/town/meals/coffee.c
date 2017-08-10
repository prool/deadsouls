#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;


static void create()  {
    meal::create();
    SetKeyName("кофе");
    SetId( ({"чашка","кофе" }) );
    SetAdjectives( ({"regular","cup of","ordinary"}) );
    SetShort("чашка кофе");
    SetLong("Самая обычная чашка кофе."); 
    SetMass(10);
    SetMealType( MEAL_DRINK | MEAL_CAFFEINE );
    SetStrength(10);
    SetBaseCost("silver",5);
    SetMealMessages("Вы выпили чашку кофе и почувствовали себя бодрее." , 
            "$N выпил $P кофе и почувствовал себя бодрее.");
}
void init(){
    ::init();
}
