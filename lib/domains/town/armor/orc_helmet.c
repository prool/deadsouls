#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

varargs int CheckOrc(object who, mixed where);

static void create(){
    armor::create();
    SetKeyName("орочий шлем");
    SetId(({"шлем"}));
    SetAdjectives(({"bear","bone","skull","orc"}));
    SetShort("орочий шлем");
    SetLong("Этот шлем сделан из толстого черепа медведя. "+
            "Внутри него мягкая подкладка для защиты головы "+
            "от сотрясений.");
    SetMass(150);
    SetBaseCost("silver",100);
    SetArmorType(A_HELMET);
    SetProtection(BLUNT, 20);
    SetProtection(BLADE, 20);
    SetProtection(KNIFE, 20);
    SetWear( (: CheckOrc :) );
}

varargs int CheckOrc(object who, mixed where){
    string race = who->GetRace();
    object env = environment(who);
    if( race == "orc"  || race == "half-orc" || race == "орк"){
        who->eventPrint("Надев шлем вы чувствуете вливающуюся в ваши мышцы "+
                "медвежью силу.");
        if(env) tell_room(env, who->GetName()+" одел "+
                GetShort()+".", ({who}));
        return 1;
    }
    else {
        who->eventPrint("Шлем сделан под орочью анатомию. "+
                "Он не подойдет вам.");
        return 0;
    }
}

void init(){
    ::init();
}
