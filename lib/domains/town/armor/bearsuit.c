#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

object bearshadow;

static void create(){
    armor::create();
    SetKeyName("медвежий костюм");
    SetId(({"костюм","медвежий","suit","медвежий костюм"}));
    SetAdjectives(({"реалистичный","ужасающий"}));
    SetShort("медвежий костюм");
    SetLong("Ужасающий и очень реалистичный костюм, одевший который "+
            "становится неотличим от медведя. Кажется, костюм "+
            "сделан из настоящих медвежих частей тела.");
    SetMass(200);
    SetMatching(0);
    SetBaseCost("silver",800);
    SetProtection(BLUNT,5);
    SetProtection(BLADE,10);
    SetProtection(KNIFE,10);
    SetArmorType(A_BODY_ARMOR);
}

void init(){
    ::init();
}

mixed eventEquip(object who, string array limbs){
    mixed success = armor::eventEquip(who, limbs);
    bearshadow = new("/shadows/bear");
    if(success){
        if(bearshadow) bearshadow->eventShadow(who);
    }
    else if(bearshadow) destruct(bearshadow);
    return success;
}

varargs mixed eventUnequip(object who) {
    mixed success;
    if(!who) who = this_player();
    success = armor::eventUnequip(who);
    if(success){
        if(bearshadow) who->unbearshadow();
    }
    return success;
}
