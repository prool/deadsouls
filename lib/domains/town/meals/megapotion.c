#include <lib.h>
#include <meal_types.h>

inherit LIB_POTION;

static void create() {
    potion::create();
    SetKeyName("зелье");
    SetId( ({ "зелье","philtrum","megapotion","зелье суперсилы" }) );
    SetShort("зелье суперсилы");
    SetLong("Это зелье значительно увеличивает силу выпившего.");
    SetMass(60);
    SetMealType(MEAL_DRINK | MEAL_ALCOHOL);
    SetStrength(5);
    SetMealMessages("Вы выпили зелье.",
            "$N выпил зелье.");
    SetBaseCost("silver",10000);
    SetDuration(30);
    SetStats( ([ "strength" : 50, "speed" : 50 ]) );
    SetSkills( ([ "bargaining" : 20, "melee defense" : 20 ]) );
    SetPoints( ([ "HP" : 100, "XP" : 100, "SP" : 100, "MP" : 100 ]) );
}
void init(){
    ::init();
}
