#include <lib.h>
#include <daemons.h>
#include <damage_types.h>
inherit LIB_NPC;

static void create(){
    npc::create();
    SetKeyName("манекен");
    SetId( ({"манекен","mokujin","buster"}) );
    SetShort("тренировочный манекен");
    SetLong("Это магический партнер для спарринга. Он вырезан "+
            "из бревен, отдаленно напоминающим человека. У него есть "+
            "голова, тело и конечности. Бревна соединяются "+
            "вместе сочленениями из цепей.");
    SetPacifist(1);
    SetBodyComposition("wood");
    SetInventory(([
                ]));
    SetLevel(10);
    SetRace("dummy");
    SetClass("fighter");
    SetGender("neuter");
    SetMaxHealthPoints(9000);
    SetHealthPoints(9000);
}

varargs int eventReceiveDamage(object agent, int type, int x, int internal, mixed limbs) {
    int hp, damage, damdiff;
    string evidence, limb_string;
    evidence = "";
    if(objectp(agent)) evidence += "Я получил урон от "+agent->GetKeyName();
    else evidence += "Я получил урон от "+agent;
    evidence += ".";
    if(type) {
        string *damtypes = TYPES_D->eventCalculateTypes("damage", type);
        if(type && sizeof(damtypes)) {
            string verboid;
            if(sizeof(damtypes) > 1) verboid = "s are ";
            else verboid = " is ";

            evidence += " Тип урона"+verboid;
            evidence += implode(damtypes,", ");
        }
        else evidence += " Тип урона НЕИЗВЕСТЕН.";
    }
    if(x) evidence += ", прямой урон "+x;
    if(internal) evidence += ", внутренняя переменная "+internal;
    if(limbs) {
        if(stringp(limbs)) limb_string = limbs;
        else if(arrayp(limbs)) {
            if(stringp(limbs[0])) limb_string = implode(limbs,", ");
            else if(objectp(limbs[0])){
                foreach(object limb in limbs){
                    limb_string += limb->GetKeyName()+", ";
                }
            }
        }
    }
    else limb_string = ", и я не могу сообщить, куда меня ударили. ";
    if(limbs) { 
        evidence += ", пораженная часть тела: ";
        evidence += limb_string + ".";
    }
    eventForce("гов "+evidence);
    hp = GetHealthPoints();

    if(!agent) agent = this_object();
    if(!type) type = 0;
    if(!x) x = 0;
    if(!internal) internal = 0;
    if(!limbs) limbs = "";

    ::eventReceiveDamage(agent, type, x, internal, limbs);

    damage = GetHealthPoints();
    damdiff = hp - damage;
    eventForce("гов фактический урон: "+damdiff);
    AddHP(damdiff+1);
}

int RemoveLimb(string limb, object agent){
    if(query_verb() == "eval" || query_verb() == "amputate" ||
            query_verb() == "call"){
        return ::RemoveLimb(limb, agent);
    }
    eventForce("гов "+limb+" получило достаточно урона для отрыва. "
            "Но, так как я - тренировочный манекен, оно останется на месте.");
    return 1;
}

void init(){
    ::init();
}
