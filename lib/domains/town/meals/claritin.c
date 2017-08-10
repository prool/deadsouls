#include <lib.h>
#include ROOMS_H
#include <meal_types.h>

inherit LIB_MEAL;

int MealCure(object who);

static void create() {
    meal::create();
    SetKeyName("пилюля");
    SetId(({"кларитин","пилюля","dose","drug"}));
    SetShort("пилюля кларитина");
    SetAdjectives(({"10mg", "10 milligram", "небольшая","non prescription", "prescription strength"}));
    SetLong("Небольшая пилюля с лекарством, устраняющим симптомы простуды.");
    SetMass(10);
    SetStrength(1);
    SetBaseCost("silver",10);
    SetMealType(MEAL_FOOD);
    SetMealAction((: MealCure :));
    SetMealMessages("Вы проглатили пилюлю.",
            "$N проглотил пилюлю.");
}
void init(){
    ::init();
}
int MealCure(object who){
    mixed *stuff;
    int effect = 0;

    if(!who) return 0;

    stuff = all_inventory(who);

    foreach(object ob in stuff){
        if(ob && ob->isGerm() && ob->GetGermName() == "cold virus"){ 
            effect = 1;
            ob->eventMove(ROOM_FURNACE);
        }
    }
    if(effect){
        tell_player(who,"Вы почувствовали себя немного лучше.");
    }

    return 1;
} 
