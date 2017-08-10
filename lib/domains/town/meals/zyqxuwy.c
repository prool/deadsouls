#include <lib.h>
#include <meal_types.h>
#include <dirs.h>

inherit LIB_FISH;

static void create() {
    fish::create();
    SetKeyName("таранька");
    SetId( ({ "рыба", "таранька" }) );
    SetAdjectives( ({ "pink","свежевыловленная","fresh water" }) );
    SetShort("таранька");
    SetLong("Это свежевыловленная рыба, сгодится на закуску.");
    SetMealType(MEAL_FOOD);
    SetMass(10); 
    SetStrength(10); 
    SetBaseCost("silver", 2);
    SetFight(4);
    SetFood("/domains/town/meals/zyqxuwy");
}
void init(){
    ::init();
}
