#include <lib.h>
#include <armor_types.h>
#include <size_types.h>
#include <damage_types.h>
inherit LIB_BANE;
inherit LIB_WORN_STORAGE;
object scoutshadow;
int active = 1;
int charge = 2000;
int maxcharge = 2000;
int disguised = 0;

varargs mixed GetSuitHelp(mixed who, string where);

static void create(){
    ::create();
    SetKeyName("экипировка следопыта");
    SetId(({"экипировка", "доспех"}));
    SetAdjectives(({"следопыта","зачарованная","powered","formidable", "formidable looking"}));
    SetShort("зачарованная экипировка следопыта");
    SetLong("Зачарованная экипировка следопыта используется представителями "+
            "Высших сил. Ее спроектировали специально для "+
            "разведки.");
    SetMass(700);
    SetMatching(0);
    SetBaseCost("silver",5000);
    SetArmorType(A_CUSTOM);
    SetRestrictLimbs( ({ 
                "torso", "head", "neck",
                "right arm", "left arm",
                "right leg", "left leg",
                "right hand", "left hand",
                "right foot", "left foot",
                }) );
    AddSave( ({ "charge", "disguised" }) );
    SetMaxCarry(500);
    SetSize(S_HUMAN_SIZED);
    SetWear((: GetSuitHelp :));
}

void init(){
    ::init();
    add_action("GetSuitHelp", "help");
}

varargs mixed GetSuitHelp(mixed who, string where){
    string ret, ret2, str;
    object env;
    if(!who) return 0;
    if(stringp(who)){
        str = who;
        who = this_player();
    }
    else str = GetKeyName();
    env = environment(who);
    if(query_verb() == "wear" || (str && answers_to(str, this_object()))){
        if(environment() == who && charge){
            ret = "Перед вашими глазами опускается дисплей, на котором написано:\n ";
            ret += "%^GREEN%^";
            ret2 = "Этот костюм позволяет тебе, славный следопыт, путешествовать по враждебным землям "+
                "с минимальными неудобствами. Для того чтобы облегчить твою непростую задачу, "+
                "костюм улучшает следующие ваши способности:\n\n"+
                "* Хорошее видение при любом освещении.\n"+
                "* Постоянный приток свежего воздуха.\n"+
                "* Существенную прибавку к силе, координации, ловкости и выносливости.\n"+
                "* Существенную прибавку к вашей способности безоружного боя.\n"+
                "* Дисплей с основной информацией об окружении.\n"+
                "* Информация о координатах, где это доступно.\n"+
                "* Защита от всех форм негативных воздействий.\n"+
                "* Иммунитет к болезням.\n\n"+
                "Будьте внимательны, когда энергия экипировки достигнет нуля, все улучшения "+
                "станут недоступны. "+
                "%^RESET%^";
            if(query_verb() == "wear" && !GetWorn()){
                who->eventPrint("Вы одели "+GetShort()+".");
                if(env) tell_room(env, who->GetName()+" одел "+
                        GetShort()+".", ({who}));
            }
            ret2 = translate(ret2, who->GetLanguageLevel("English"));
            who->eventPrint(ret+ret2);
            return 1;
        }
    }
    return 0;
}

mixed eventEquip(object who, string array limbs){
    mixed success = ::eventEquip(who, limbs);
    scoutshadow = new("/shadows/scout");
    if(scoutshadow) scoutshadow->SetDisguised(disguised);
    if(success){
        if(scoutshadow) scoutshadow->eventShadow(who);
    }
    else if(scoutshadow) destruct(scoutshadow);
    return success;
}

varargs mixed eventUnequip(object who) {
    mixed success;
    if(!who) who = this_player();
    success = ::eventUnequip(who);
    if(success){
        if(scoutshadow) who->unscoutshadow();
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
    if(previous_object() != scoutshadow) return 0;
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
        tell_object(env,remove_article(GetShort())+" подала громкий сигнал!");
        return charge;
    }

    if(perc < 20){
        if(living(env) && creatorp(env)){
            env->eventPrint("Ваша сверхестественная сила перезарядила "+
                    remove_article(GetShort())+".");
            charge = maxcharge;
            return charge;
        }
        tell_object(env,remove_article(GetShort())+" подала громкий сигнал.");
        return charge;
    }

    return charge;
}

int GetRemainingCharge(){
    if(!charge || !GetWorn()){
        if(scoutshadow) scoutshadow->eventUnshadow();
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
