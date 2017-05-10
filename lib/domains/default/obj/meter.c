#include <lib.h>
#include <vendor_types.h>
#include <vision.h>
inherit LIB_ITEM;

varargs string translate_vision(object ob){
    int vision;
    string ret = " ";
    if(!ob) vision = this_player()->GetEffectiveVision();
    else vision = ob->GetEffectiveVision();
    switch(vision){
        case 0 : ret = "уровень 0: ничего не видно.";break; 
        case 1 : ret = "уровень 1: очень темно.";break; 
        case 2 : ret = "уровень 2: темно.";break; 
        case 3 : ret = "уровень 3: тускло.";break; 
        case 4 : ret = "уровень 4: ясно.";break; 
        case 5 : ret = "уровень 5: светло.";break; 
        case 6 : ret = "уровень 6: ярко.";break; 
        case 7 : ret = "уровень 7: очень ярко.";break; 
        default : ret = "не понятно.";
    }
    return ret;
}

varargs mixed EvaluateRadiantLight(object ob, int report){
    int x = 0;
    string rep = "";
    string subrep = "";
    if(!ob) ob = this_player();
    foreach(object guy in get_livings(environment(ob))){
        if(guy->GetRadiantLight()) 
            rep += guy->GetName()+" испускающий свет: "+guy->GetRadiantLight()+".\n";
        foreach(object item in all_inventory(guy)){
            x += item->GetRadiantLight();
            if(item->GetRadiantLight()){
                subrep += guy->GetName()+"'s "+item->GetName()+" испускающий свет: "+
                    item->GetRadiantLight()+".\n";
            }
        }
    }
    if(!report) return x;
    else return "Существа: \n"+rep+"\nОбъекты:\n"+subrep;
}

string DefaultReading(){
    write("Это маленькое устройство - портативный измеритель освещенности. Оно показывает "+
            "вам сколько тут света.");
    write("Окружающий свет здесь: "+environment(this_player())->GetAmbientLight());
    write("Общий испускающий свет: "+EvaluateRadiantLight());
    write("Ваша дальность видимости: "+this_player()->GetEffectiveVision(environment(this_player()),1));
    write("\nВаше эффективное видение "+translate_vision());
    write("\nПолная информация о освещенности:\n"+EvaluateRadiantLight(this_player(),1));
    return "";
}

varargs mixed eventUse(mixed arg){
    return DefaultReading();
}

void create(){
    ::create();
    SetKeyName("люксметр");
    SetAdjectives( ({"освещенности"}) );
    SetId( ({"meter", "люксметр"}) );
    SetShort("люксметр");
    SetLong( (: DefaultReading :) );
    SetProperties(([
                "no steal" : 1,
                ]));
    SetNoCondition(1);
    SetMass(20);
    SetVendorType(VT_TREASURE);
}
void init(){
    ::init();
}
