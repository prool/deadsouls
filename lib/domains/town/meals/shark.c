/*    /domains/Ylsrim/fish/shark.c
 *    from the Dead Souls Mud Library
 *    created by Descartes of Borg 960302
 */

#include <lib.h>
#include <meal_types.h>
#include <dirs.h>
#include <damage_types.h>

inherit LIB_FISH;

void BiteMe(object who);
static void create() {
    fish::create();
    SetKeyName("бычья акула");
    SetId( ({ "акула", "бычья акула" }) );
    SetShort("бычья акула");
    SetLong("Это огромная жирная рыбина с зубами, напоминающими кривые сабли, и "
            "ненасытным аппетитом.");
    SetMealType(MEAL_FOOD);
    SetMass(100); 
    SetStrength(50);
    SetBaseCost("silver", 10);
    SetFight(40);
    SetFood("/domains/town/meals/shark");
}
int eventCatch(object who, object pole) { 
    call_out((: BiteMe, who :), 0);
    return 1;
}
void BiteMe(object who) {
    who->eventPrint("Акула укусила вас перед смертью!");
    environment(who)->eventPrint("Акула укусила " + who->GetName() +
            " перед смертью!", who);
    who->eventReceiveDamage(this_object(), BITE, random(30), 0,
            who->GetRandomLimb("right hand"));
}
void init(){
    ::init();
}
