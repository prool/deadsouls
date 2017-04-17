#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_BANE;
inherit LIB_WORN_STORAGE;
object arbitershadow;
int active = 1;
int charge = 20000;
int maxcharge = 20000;
int disguised = 0;

varargs mixed GetSuitHelp(mixed who, string where);

static void create(){
    ::create();
    SetKeyName("мантия Судьи");
    SetId(({"мантия", "судьи", "мантию"}));
    SetAdjectives(({"усиленная","suit of","powered","formidable", "formidable looking"}));
    SetShort("мантия Судьи");
    SetLong("Эта мантия усилена пластинами небесной стали, что позволяет "+
            "ее обладателю не только выносить приговоры, но и собственноручно "+
            "исполнять их.");
    SetMass(7000);
    SetMatching(0);
    SetBaseCost("silver",50000);
    SetArmorType(A_CUSTOM);
    SetRestrictLimbs( ({ 
                "torso", "head", "neck",
                "right arm", "left arm",
                "right leg", "left leg",
                "right hand", "left hand",
                "right foot", "left foot",
                }) );
    AddSave( ({ "charge", "disguised" }) );
    SetMaxCarry(5000);
    SetWear((: GetSuitHelp :));
}

void init(){
    ::init();
    add_action("GetSuitHelp", "help");
}

varargs mixed GetSuitHelp(mixed who, string where){
    string ret, str;
    object env;
    if(!who) return 0;
    if(stringp(who)){
        str = who;
        who = this_player();
    }
    else str = GetKeyName();
    env = environment(who);
    if(query_verb() == "одеть" || (str && answers_to(str, this_object()))){
        if(environment() == who && charge){
            ret = "Перед вами возникают светящиеся буквы:\n ";
            ret += "%^GREEN%^Это одеяние позволяет вам, могучий Судия, путешествовать по опасным землям "+
                "с минимальным риском. Для исполнения ваших обязанностей  "+
                "мантия дает следующие способности:\n\n"+
                "* хорошее зрение при любом освещении;\n"+
                "* постоянный приток свежего воздуха;\n"+
                "* сущестсвенную прибавку к силе, координации, ловкости и устойчивости;\n"+
                "* существенную прибавку к способности безоружного боя;\n"+
                "* невидимый дисплей с информацией о происходящем;\n"+
                "* информация о ваших координатах, где это возможно;\n"+
                "* защиту от любых форм повреждений;\n"+
                "* иммунитет к болезням.\n"+
                "\nОднако, если магический заряд мантии достигнет нуля, все ее бонусы "+
                "станут недоступны.%^RESET%^";
            who->eventPrint("Вы одели "+GetShort()+".");
            if(env) tell_room(env, who->GetName()+" одел "+
                    GetShort()+".", ({who}));
            return 1;
        }
    }
    return 0;
}

mixed eventEquip(object who, string array limbs){
    mixed success = ::eventEquip(who, limbs);
    arbitershadow = new("/shadows/arbiter");
    if(arbitershadow) arbitershadow->SetDisguised(disguised);
    if(success){
        if(arbitershadow) arbitershadow->eventShadow(who);
    }
    else if(arbitershadow) destruct(arbitershadow);
    return success;
}

varargs mixed eventUnequip(object who) {
    mixed success;
    if(!who) who = this_player();
    success = ::eventUnequip(who);
    if(success){
        if(arbitershadow) who->unarbitershadow();
    }
    return success;
}

int GetActive(){
    if(!charge) return 0;
    return active;
}

int SetActive(int i){
    if(i) active = 1;
    else active = 0;
    return active;
}

int eventDecrementCharge(int i){
    int perc;
    object env = environment();
    if(!env) return 0;

    if(!GetWorn()) return 0;
    if(previous_object() != arbitershadow) return 0;
    if(charge < 1) charge = 0;
    else { 
        if(!i) charge--;
        else charge -= i;
        if(charge < 0) charge = 0;
    }

    perc = to_int(percent(charge, maxcharge));
    if(perc < 10){
        if(living(env) && creatorp(env)){
            env->eventPrint("Ваша сверхестественная сила перезарядила "+
                    remove_article(GetShort())+".");
            charge = maxcharge;
            return charge;
        }
        tell_object(env,remove_article(GetShort())+" ярко заискрилась!");
        return charge;
    }

    if(perc < 20){
        if(living(env) && creatorp(env)){
            env->eventPrint("Ваша сверхестественная сила перезарядила "+
                    remove_article(GetShort())+".");
            charge = maxcharge;
            return charge;
        }
        tell_object(env,remove_article(GetShort())+" слабо заискрилась.");
        return charge;
    }

    return charge;
}

int GetRemainingCharge(){
    if(!charge || !GetWorn()){
        if(arbitershadow) arbitershadow->eventUnshadow();
        return 0;
    }
    return charge;
}

int GetMaxCharge(){
    return maxcharge;
}

int SetCharge(int i){
    charge = i;
    return charge;
}

int SetMaxCharge(int i){
    maxcharge = i;
    return maxcharge;
}

string array GetBane(){
    if(GetActive()) return ({ "all" });
    else return ({});
}

string array QueryBane(){
    if(GetActive()) return ({ "all" });
    else return ({});
}
