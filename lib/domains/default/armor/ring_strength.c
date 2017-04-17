#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

varargs int DoWear(object who, string where);
int CheckRing(string stat);

static void create(){
    armor::create();
    SetKeyName("кольцо");
    SetId(({"кольцо"}));
    SetAdjectives( ({"магическое", "тяжелое", "металлическое"}) );
    SetShort("тяжелое металлическое кольцо");
    SetLong("Это кольцо как будто пульсирует силой.");
    SetMass(10);
    SetBaseCost("silver",5000);
    SetArmorType(A_RING);
    SetWear((: DoWear :));
    SetUnique(1);
}

void init(){
    ::init();
}

varargs int DoWear(object who, string where){
    object env = environment(who);
    who->AddStatBonus("strength", (: CheckRing :) );
    who->eventPrint("Вы почувствовали наливающиеся силой мышцы, "+
            "как только одели кольцо.");
    if(env) tell_room(env, who->GetName()+" одел "+GetShort()+".", ({who}));
    return 1;
}

int CheckRing(string stat) {
    if( !GetWorn() ) {
        previous_object()->RemoveStatBonus("strength", this_object());
        return 0;
    }
    else return 5;
}
