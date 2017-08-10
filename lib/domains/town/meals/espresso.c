#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;


static void create()  {
    meal::create();
    SetKeyName("эспрессо");
    SetId( ({"чашка","эспрессо" }) );
    SetAdjectives( ({"imported","cup of"}) );
    SetShort("чашка эспрессо");
    SetLong("Чашка одной из разновидностей кофе - эспрессо."); 
    SetMass(10);
    SetMealType( MEAL_DRINK | MEAL_CAFFEINE );
    SetStrength(20);
    SetBaseCost("silver",15);
    SetMealMessages("Вы выпили чашку эспрессо и почувствовали себя бодрее." , 
            "$N выпил $P эспрессо и почувствовал себя бодрее.");
}
void init(){
    ::init();
}
