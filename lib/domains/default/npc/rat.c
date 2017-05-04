#include <lib.h>

inherit LIB_SENTIENT;

int CheckRat(mixed val){
    string *allowed_races = ({ "orc", "half-orc", "rodent" });
    if(!val) return 0;
    if(!objectp(val)) return 0;
    if(member_array(val->GetRace(), allowed_races) != -1) return 0;
    return 1;
}

static void create() {
    sentient::create();
    SetKeyName("крыса");
    SetAdjectives( ({"маленькую", "маленькая", "грязная"}) );
    SetId( ({"крыса"}) );
    SetShort("крыса");
    SetLong("Вы видите маленькую грязную крыса.");
    SetLevel(3);
    SetMaxHealthPoints(50);
    SetRace("rodent");
    SetGender("female");
    SetClass("fighter");
    SetWanderSpeed(1);
    SetEncounter( (: CheckRat :) );
    SetMessage("come","$N scurries in.");
    SetMessage("leave","$N scurries $D.");
    SetAction(5, ({ 
                "Крыса тревожно запищала", "Вы слышите, как здесь шуршит крыса.", 
                "Маленькая грязная крыса проскользнула мимо ваших ног.",
                "Крыса что-то грызет."}));
}
void init(){
    ::init();
}
