#include <lib.h>
#include <vendor_types.h>
#include <meal_types.h>
inherit LIB_FLASK;

void create(){
    ::create();
    SetKeyName("бутылка");
    SetId( ({"виски","vessel","бутылка виски","rebel yell"}) );
    SetAdjectives( ({"whiskey","glass","rebel yell"}) );
    SetShort("бутылка виски");
    SetLong("Бутылка с отличным виски.");
    SetMass(40);
    SetBaseCost("gold",3);
    SetVendorType(VT_DRINK);
    SetFlaskContents("whiskey");
    SetFlaskUses(10);
    SetStrength(30);
    SetMaxFlask(10); 
    SetMealType(MEAL_ALCOHOL);
    SetItems(([
      "этикетка" : "На бутылке есть этикетка с изображением "+
        "солдата на лошади в серой униформе "+
        "с поднятой саблей.",
    ]));
    SetReads(([
      "этикетка" : "REBEL YELL",
    ]));
}
void init(){
    ::init();
}
