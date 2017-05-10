#include <lib.h>
#include <vendor_types.h>

inherit LIB_STORAGE;
inherit LIB_PRESS;
inherit LIB_INSTALL;
inherit LIB_ACTIVATE;

string oportal = "/secure/obj/portal_orange";
string bportal = "/secure/obj/portal_blue";

varargs mixed CheckOrange(int ob){
    object o, *tmp;
    int orange = sizeof(tmp=filter(deep_inventory(this_object()),
                (: base_name($1) == "/domains/default/obj/vial_orange" :) ) );
    if(orange) o = tmp[0];
    if(ob) return o;
    return orange;
}

varargs mixed CheckBlue(int ob){
    object b, *tmp;
    int blue = sizeof(tmp=filter(deep_inventory(this_object()),
                (: base_name($1) == "/domains/default/obj/vial_blue" :) ) );
    if(blue) b = tmp[0];
    if(ob) return b;
    return blue;
}

string ExaOrange(){
    string ret = "Оранжевая кнопка. ";
    if(CheckOrange()) ret += "Она светится.";
    else ret += "Она темнеет.";
    return ret;
}

string ExaBlue(){
    string ret = "Синяя кнопка. ";
    if(CheckBlue()) ret += "Она светится.";
    else ret += "Она темнеет.";
    return ret;
}  

mixed PressOrange(mixed args...){
    int orange = CheckOrange();
    if(orange){
        orange = new(oportal)->eventMove(environment(this_player()));
    }
    if(orange){
        write("Вы нажали кнопку и с низким гулом "+
                "появился оранжевый портал.");
        say(this_player()->GetName()+" нажал кнопку "+
                possessive(this_player())+" генератора портала "+
                "и с низким гулом появился оранжевый портал.");
    }  
    else {
        write("Клик.");
        say(this_player()->GetName()+" нажал кнопку "+
                possessive(this_player())+" генератора портала.");
    }
    return 1;
}

mixed PressBlue(mixed args...){
    int blue = CheckBlue();
    if(blue){
        blue = new(bportal)->eventMove(environment(this_player()));
    }
    if(blue){
        write("Вы нажали кнопку и с низким гулом "+
                "появился синий портал.");
        say(this_player()->GetName()+" нажал кнопку "+
                possessive(this_player())+" генератора портала "+
                "и с низким гулом появился синий портал.");
    }
    else {
        write("Клик.");
        say(this_player()->GetName()+" нажал кнопку "+
                possessive(this_player())+" генератора портала.");
    }
    return 1;
}

string ReadLabel(){
    string ret = "";
    ret += "GCM Heavy Industries Portal Generator Mk I\n\n";
    ret += "* Please read this beard to know act According to carry on!\n";
    ret += "* no portaling through between same room allowed Interdicted!\n";
    ret += "* Please the human user to be sign release form the organs!\n";
    ret += "* If you are stolen, call the police at once!\n";
    ret += "* values of "+sprintf("%c",223)+" may give rise to dom!\n";
    return ret;
}

string ReadScribbles(){
    string ret = "";
    ret += "this technology was stolen by GCM and they don't understand it. ";
    ret += "NOBODY HAS EVER RETURNED FROM USING PORTALS IN THE SAME ROOM! ";
    ret += "and whatever you do, stay away from th\n";
    return ret;
}

void create(){
    ::create();
    SetKeyName("GCM Portal Generator Mk I");
    SetId( ({"генератор", "устройство", "generator mk i","генератор портала"}) );
    SetAdjectives( ({"блестящее","mk i","футуристическое","portal","gcm"}) );
    SetShort("генератор портала");
    SetLong("Это блестящее футуристическое устройство с оранжевыми и "+
            "синими кнопками. Вы видите на нем метку производителя и "+
            "корявую инструкцию.");
    SetMass(100);
    SetBaseCost("silver",5000);
    SetVendorType(VT_TREASURE);
    SetItems( ([
                ({"метка","метку"}) : "На метке производителя что-то написано.",
                ({"инструкция","инструкции","scribbled markings"}) : "Инструкция "+
                "написана наспех и не очень понятная.",
                ({ "кнопка", "кнопки" }) : "У генератора портала две кнопки - "+  
                " оранжевая и синяя.",
                ({ "оранжевая кнопка" }) : (: ExaOrange :),
                ({ "синяя кнопка" }) : (: ExaBlue :),
                ]) );
    SetReads( ([
                "default" : "Попробуйте 'read метка'",
                ({"метка","метку"}) : (: ReadLabel :),
                ({"инструкция","инструкции","scribbled markings"}) : (: ReadScribbles :),
                ]) );
    SetPress( ([
                "default" : "Попробуйте 'push синяя кнопка'",
                ({ "кнопка", "кнопки" }) : "Вы можете нажать либо ту, либо эту.",
                ({"оранжевая кнопка"}) : (: PressOrange :),
                ({"синяя кнопка"}) : (: PressBlue :),
                ]) );
    SetMaxCarry(200);
    SetUnique(1);
}

varargs mixed eventInstall(object what, object where){
    write("Генератор портала не может быть установлен в любом месте.");
    return 1;
}

mixed CanPutInto(object who, object item){
    return "Это генератор портала. В него можно установить дополнительные модули.";
}

mixed CanGetFrom(object who, object item){
    return "Это генератор портала. Из него можно вынуть дополнительные модули.";
}

int CanReceive(object ob){
    if(base_name(ob) == "/domains/default/obj/vial_blue"){
        if(CheckBlue()){
            write("Это не подходит.");
            return 0;
        }
        else return 1;
    }
    if(base_name(ob) == "/domains/default/obj/vial_orange"){
        if(CheckOrange()){
            write("Это не подходит.");
            return 0;
        }
        else return 1;
    }
    write("Это не отсюда.");
    return 0;
}

int eventTurnOn(){
    write("Попробуйте 'push оранжевая кнопка'");
    return 1;
}

void init(){
    ::init();
}
