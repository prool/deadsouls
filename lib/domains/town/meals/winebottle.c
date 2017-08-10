#include <lib.h>
#include <vendor_types.h>
#include <meal_types.h>
inherit LIB_FLASK;

void create(){
    ::create();
    SetKeyName("бутылка");
    SetId( ({"vessel","бутылка","бутылка вина","nouveau"}) );
    SetAdjectives( ({"вино","glass","nouveau"}) );
    SetShort("бутылка вина");
    SetLong("Это бутылка дешевого вина. Ее этикетка слишком грязная, чтобы на ней можно было что-нибудь разобрать.");
    SetMass(40);
    SetBaseCost("gold",2);
    SetVendorType(VT_DRINK);
    SetFlaskContents("wine");
    SetFlaskUses(10);
    SetStrength(20);
    SetMaxFlask(10); 
    SetMealType(MEAL_ALCOHOL);
    SetItems(([
      "этикетка" : "Она приклеена к бутылке и ее можно прочесть.",
    ]));
    SetReads(([
      "этикетка" : "Она слишком грязная, ее не получается прочесть.",
    ]));
}
void init(){
    ::init();
}
