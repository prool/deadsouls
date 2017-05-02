#include <lib.h>

inherit LIB_SENTIENT;

int StealAttempt(){
    object *players = get_livings(environment(this_object()),1);
    object *stuff;
    object target;
    string name, thing;
    int which, whether;

    if(sizeof(players)){
        which = random(sizeof(players));
        target = players[which];
        name = target->GetKeyName();
        stuff = all_inventory(target);
        if(!sizeof(stuff) || random(100) > 50) whether = 1;
        if(whether) this_object()->eventForce("steal money from "+name);
        else {
            thing = stuff[random(sizeof(stuff))]->GetKeyName();
            this_object()->eventForce("steal "+thing+" from "+name);
        }
    }
    whether = 0;
    return 1;
}

static void create() {
    sentient::create();
    SetKeyName("кендер");
    SetId(({"нпс","моб","существо","кендер"}));
    SetAdjectives(({"non-player", "non player"}));
    SetShort("кендер");
    SetLong("Кендеры - это печально известная своей клептоманией разновидность хоббитов. Говорят, что они учатся красть раньше, чем учатся читать. Хотя злые языки утверждают, что кендеры читать вообще не умеют.");
    SetClass("thief");
    SetLevel(5);
    SetMelee(1);
    SetRace("kender");
    SetGender("female");
    SetAction(25, ({
                (: StealAttempt :),
                }) );
}
void init(){
    ::init();
}
