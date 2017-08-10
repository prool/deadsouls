#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;
inherit LIB_MEAL_POISON;


static void create() {
    ::create();
    SetKeyName("яд");
    SetId( ({ "склянка", "яд", "vial of poison" }) );
    SetAdjectives("glass","маленькая");
    SetShort("склянка с ядом");
    SetLong("Маленька склянка с самым сильным змеиным ядом.");
    SetMass(60);
    SetMealType(MEAL_DRINK);
    SetStrength(1);
    SetMealMessages("Вы выпили из склянки.",
            "$N выпил из склянки.");
    SetEmptyName("склянка");
    SetEmptyShort("пустая склянка");
    SetEmptyLong("Это пустая маленькая склянка.");
    SetBaseCost("silver",10);
    SetPoisonStrength(70);
    SetPoisonUses(3);
}
mixed eventDrink(object who) {
    who->AddPoison(this_object()->GetPoisonStrength() * this_object()->GetPoisonUses());
    return ::eventDrink(who);
}
void init(){
    ::init();
}
