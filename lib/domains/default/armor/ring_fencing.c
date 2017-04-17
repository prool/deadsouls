#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

varargs int DoWear(object who, string where);
int CheckRing(string skill);

static void create(){
    armor::create();
    SetKeyName("кольцо");
    SetId(({"кольцо"}));
    SetAdjectives( ({"магическое", "тонкое", "простое"}) );
    SetShort("тонкое кольцо");
    SetLong("Это простое кольцо создано из тонкой "+
            "скрученной проволоки.");
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
    who->AddSkillBonus("blade attack", (: CheckRing :) );
    who->AddSkillBonus("blade defense", (: CheckRing :) );
    who->eventPrint("Вы одели кольцо и почувствовали себя ловче..."+
            "и немного бодрее.");
    if(env) tell_room(env, who->GetName()+" одел "+GetShort()+".", ({who}));
    return 1;
}

int CheckRing(string skill) {
    if( !GetWorn() ) {
        previous_object()->RemoveSkillBonus("blade attack", this_object());
        previous_object()->RemoveSkillBonus("blade defense", this_object());
        return 0;
    }
    else return 5;
}
