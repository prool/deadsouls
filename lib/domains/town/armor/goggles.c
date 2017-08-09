#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("защитные очки");
    SetId(({"защитные очки"}));
    SetAdjectives(({"толстые","driving","защитные","eyewear"}));
    SetShort("защитные очки");
    SetLong("Эти очки сделаны из толстых стекол в прочной оправе, для защиты "+
            "глаз от мелких камней и веток.");
    SetMass(5);
    SetBaseCost("silver",30);
    SetArmorType(A_VISOR);
}

void init(){
    ::init();
}

int eventReceiveDamage(mixed agent, int type, int amt, int i, mixed array l){
    if(GetWorn()){
        tell_object(environment(this_object()), "Защитные очки! Они "+
                "не работают!");
    }
    return ::eventReceiveDamage(agent, type, amt, i, l);          
}


