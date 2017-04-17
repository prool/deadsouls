#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;
object ringshadow;

string LongRet(mixed whom){
    string ret = "Зеленое кольцо светящееся неземной силой.";
    if(!whom || !objectp(whom) || !living(whom)) whom = this_player();
    if(creatorp(whom) ||
            member_group(whom,"TEST")){
        ret += "\nАктивация защиты от урона: protection on";
        ret += "\nАктивация сообщений о типах урона: reporting on";
        ret += "\nЗаставить существо сообщить свой урон: enablereport <name>";
        ret += "\nОтмена сообщений существа о его уроне: disablereport <name>\n";
    }
    return ret;
}

static void create(){
    armor::create();
    SetKeyName("нефритовое кольцо");
    SetId(({"кольцо","оберег","нефрит"}));
    SetAdjectives( ({"нефритовое","зеленое"}) );
    SetShort("нефритовое кольцо");
    SetLong( (: LongRet :) );
    SetMass(1);
    SetBaseCost("silver",5000);
    SetArmorType(A_RING);
}

void init(){
    armor::init();
    add_action("SetProtection", "protection");
    add_action("SetReporting", "reporting");
    add_action("SetNPCReporting", "enablereport");
    add_action("UnsetNPCReporting", "disablereport");
}

mixed CanEquip(object who, string array limbs){
    if(who && !creatorp(who) && !member_group(who,"TEST")){
        return "Кольцо не лезет на наш палец. Странно, не так ли?";
        return 0;
    }
    else return armor::CanEquip(who, limbs);
}

int eventRegenerate(object who){
    int i;
    string *stumps;
    stumps=who->GetMissingLimbs();
    if(sizeof(stumps)) {
        for(i=0;i<sizeof(stumps);i++){
            who->RestoreLimb(stumps[i]);
        }
    }
    return 1;
}

int PerformHeal(){
    object who;
    mapping stumps;
    string *limb_arr = ({});
    int i, mhp, msp, mmp, self;

    who = this_player();

    mhp = who->GetMaxHealthPoints();
    msp = who->GetMaxStaminaPoints();
    mmp = who->GetMaxMagicPoints();
    who->AddHP(mhp);
    who->AddStaminaPoints(msp);
    who->AddMagicPoints(mmp);
    if(who->GetPoison() > 0) who->AddPoison(0 - who->GetPoison());
    eventRegenerate(who);
    limb_arr = who->GetLimbs();
    foreach(string limb in limb_arr) {
        who->HealLimb(limb);
    }
    return 1;
}

int CheckRing(){
    if(environment() != this_player()) return 0;
    if(!(this_object()->GetWorn())) return 0;
    if(!creatorp(environment()) && 
            !member_group(environment(),"TEST")) return -1;
    return 1;
}

int SetNPCReporting(string name){
    object *sombras = ({});
    object ob;
    if(!CheckRing() || !ringshadow){
        write("Кольцо должно быть одето на вас, чтобы вам была доступна его сила.");
        return 1;
    }
    if(CheckRing() == -1){
        write("Сила кольца открывается лишь не обычным людям. Это значит, \"не вы\".");
        return 1;
    }
    if(!(ob = present(name,environment(this_player())))){
        write("Такого существа здесь нет");
        return 1;
    }
    sombras = keys(ob->GetShadows());
    if(sizeof(sombras)){
        foreach(object element in sombras){
            if(base_name(element) == "/shadows/diag"){
                write("Это существо уже сообщает о своем уроне.");
                return 1;
            }
        }
    }
    new("/shadows/diag")->eventShadow(ob);
    write(""+name+": сообщает о своем уроне.");
    return 1;
}

int UnsetNPCReporting(string name){
    object *sombras = ({});
    object ob;
    int stat = 0;
    if(!CheckRing() || !ringshadow){
        write("Кольцо должно быть одето на вас, чтобы вам была доступна его сила.");
        return 1;
    }
    if(CheckRing() == -1){
        write("Сила кольца открывается лишь не обычным людям. Это значит, \"не вы\".");
        return 1;
    }
    if(!(ob = present(name,environment(this_player())))){
        write("Такого сушества здесь нет.");
        return 1;
    }
    sombras = keys(ob->GetShadows());
    if(sizeof(sombras)){
        foreach(mixed element in sombras){
            if(element && objectp(element) && base_name(element) == "/shadows/diag"){
                stat = 1;
                element->eventUnshadow();
            }
        }
    }
    if(!stat) write("Это существо не сообщает о своем уроне.");
    else write(""+name+": прекратило сообщать о своем уроне.");
    return 1;
}

int SetProtection(string str){
    int booly = 0;
    if(!CheckRing() || !ringshadow){
        write("Кольцо должно быть одето на вас, чтобы вам была доступна его сила.");
        return 1;
    }
    if(CheckRing() == -1){
        write("Сила кольца открывается лишь не обычным людям. Это значит, \"не вы\".");
        return 1;
    } 
    if(str == "on") booly=1;
    write("Защита нефритового кольца: "+(booly ? "on" : "off")+".");
    if(ringshadow) ringshadow->JadeProtection(booly);
    return 1;
}

int SetReporting(string str){
    int booly = 0;
    if(!CheckRing() || !ringshadow){
        write("Кольцо должно быть одето на вас, чтобы вам была доступна его сила.");
        return 1;
    }
    if(CheckRing() == -1){
        write("Сила кольца открывается лишь не обычным людям. Это значит, \"не вы\".");
        return 1;
    }
    if(str == "on") booly=1;
    write("Сообщения нефритового кольца: "+(booly ? "on" : "off")+".");
    if(ringshadow) ringshadow->JadeReporting(booly);
    return 1;
}

mixed eventEquip(object who, string array limbs){
    int ok = 0;
    mixed success = armor::eventEquip(who, limbs);
    if(!ringshadow){
        object *sombras = keys(who->GetShadows());
        ok = 1;
        ringshadow = new("/shadows/ring");
        foreach(object element in sombras){
            if(base_name(element) == base_name(ringshadow)){
                ok = 0;
                if(ringshadow) destruct(ringshadow);
                ringshadow = element;
            }
        }
    }
    if(success){
        PerformHeal();
        if(ok){
            if(ringshadow) ringshadow->eventShadow(who);
            if(ringshadow) ringshadow->JadeProtection(1);
        }
    }
    else if(ringshadow) destruct(ringshadow);
    return success;
}

varargs mixed eventUnequip(object who) {
    mixed success;
    if(!who) who = this_player();
    success = armor::eventUnequip(who);
    if(success){
        if(ringshadow) ringshadow->eventUnshadow(ringshadow);
    }
    return success;
}
