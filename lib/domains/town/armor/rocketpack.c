#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
#include <medium.h>
inherit "/domains/default/armor/rocketpack";


string LongD(){
    string ret = "Это небольшое устройство носится на спине и позволяет \"boost\" " +
        "носящему взлетать в воздух. Чтобы использовать, "+
        "его нужно сначала активировать.  Индикатор топлива "+
        "показывает "+to_int(percent(charge,maxcharge))+" %.";
    return ret;
}

static void create(){
    ::create();
    if(!Directions) Directions = ([]);
    SetKeyName("ракетный ранец");
    SetId(({"ранец","rocket","ракетный ранец"}));
    SetAdjectives(({"small","ракетный"}));
    SetShort("ракетный ранец");
    SetLong( (: LongD :) );
    SetMass(500);
    SetBaseCost(8000);
    SetArmorType(A_ARMOR);
    AddSave( ({ "charge", "Directions" }) );
    SetRestrictLimbs( ({ "torso" }) );
    SetCharge(200);
    SetMaxCharge(200);
}

void init(){
    ::init();
}
