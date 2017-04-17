// The carrier of this amulet will not be forced to quit
// if they hit their max idle time. Also speeds magic point refresh.

#include <lib.h>
#include ROOMS_H
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("серый амулет");
    SetId(({"амулет", "серый", "idler_amulet" }));
    SetShort("серый амулет");
    SetLong("Этот простой тяжелый амулет кажется бесполезным, "
            "хотя в нем скрыты магические свойства.");
    SetProperties(([
                "no steal" : 1,
                ]));
    SetMass(50);
    SetBaseCost(100000);
    SetArmorType(A_AMULET);
    SetRetainOnDeath(1);
    SetRestrictLimbs( ({ "torso" }) );
    set_heart_beat(7);
}

void init(){
    ::init();
}

void heart_beat(){
    object env = environment();
    if(env && living(env) && GetWorn()){
        env->AddMagicPoints(1);
    }
}

