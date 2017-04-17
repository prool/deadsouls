#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ACTIVATE;
inherit LIB_INSTALL;
inherit LIB_WORN_STORAGE;

static int active = 0;
int lupus;
mapping SpecialFuns = ([]);

int CheckPanel(){
    if(this_object()->GetClosed()){
        write("Переносной компьютер закрыт, дисплей не доступен.");
    }
    else {
        write("Инофрмация на дисплее доступна.");
    }
    return 1;
}

static void create() {
    worn_storage::create();
    SetKeyName("переносной компьютер");
    SetId( ({ "компьютер", "браслет","система" }) );
    SetAdjectives( ({ "ручной","странный","сложный","прочный","надежный",
                 "информационный" }) );
    SetShort("переносной компьютер");
    SetLong("Этот странно выглядящий браслет носится на руке. Он выглядит "
            "очень сложным, но также прочным и надежным. Вы вероятно можете "
            "\"activate bracer\". Вероятно вам станут доступны специальные функции, "
            "когда откроете его.");
    SetDamagePoints(75);
    SetVendorType(VT_ARMOR);
    SetMass(10);
    SetBaseCost("silver", 1000);
    SetArmorType(A_CUSTOM);
    SetProtection(BLUNT, 10);
    SetProtection(BLADE, 10);
    SetProtection(KNIFE, 20);
    SetProtection(HEAT, 30);
    SetRestrictLimbs(({"left arm"}));
    SetMaxCarry(100);
    SetCanClose(1);
    SetClosed(1);
    SetLanguage("Yautja");
    SetItems( ([
                ({"panel","functions"}) : (: CheckPanel :),
                ]) );
    SetRead( ([
                ({ "panel", "default" }) :"Тактическая информационная система, версия .09",
                //"panel": (: eventRead :),
                ]) );
    SetMaxClones(2);
}

int eventInitialize(){
    object env;
    if(!(env = environment()) || !living(env)) return 0;
    foreach(object module in all_inventory()){
        if(module) module->eventInstall(env, this_object());
    }
    return 1;
}

void init(){
    ::init();
    eventInitialize();
}

int eventMove(mixed arg){
    eventInitialize();
    return ::eventMove(arg);
}

varargs int YautLang(object whom){
    if(!whom) whom = this_player(); 
    if(!whom) return 0;
    if(whom->GetPolyglot()) return 100;
    return whom->GetLanguageLevel("Yautja");
}

varargs void yaut_write(string str, object whom){
    if(!str || !sizeof(str)) return;
    if(!whom) write("%^MAGENTA%^"+translate(str,YautLang())+"%^RESET%^");
    else tell_object(whom,"%^MAGENTA%^"+translate(str,YautLang(whom))+"%^RESET%^");
}

varargs void yaut_say(string str, mixed whom){
    object *exclude = ({});
    object *include = get_livings(environment(this_player()));
    if(whom){
        if(objectp(whom)) exclude = ({ whom });
        else exclude = whom;
    }
    include -= exclude;
    if(sizeof(include))
        foreach(object dude in include){
            yaut_write(str, dude);
        }
}

int eventTurnOn(){
    object *contents = all_inventory();
    if(!(this_object()->GetWorn()) || !this_player() ||
            environment(this_object()) != this_player()){
        write("На вас не одет переносной компьютер.");
        return 1;
    }
    write("Вы активируете переносной компьютер. Появляется информация:");
    say(this_player()->GetName()+" использует "+possessive(this_player())+" "
            "переносной компьютер. Вы слышите доносящийся звук: "); 
    yaut_say("Computer online.");
    if(sizeof(contents)) contents->eventPowerOn();
    active = 1;
    return 1;
}

int eventTurnOff(){
    object *contents = all_inventory();
    write("Вы деактивируете переносной компьютер. Появляется информация:");
    say(this_player()->GetName()+" использует "+possessive(this_player())+" "
            "переносной компьютер. Вы слышите доносящийся звук: ");
    yaut_say("Computer offline.");
    if(sizeof(contents)) contents->eventPowerOff();    
    active = 0;
    return 1;
}

varargs mixed eventInstall(object what, object where){
    write("Переносной компьютер не может быть установлен в любом месте.");
    return 1;
}

int CanReceive(object ob){
    if(!answers_to("Информационный модуль",ob)){
        write("Это не подходящий информационный модуль для этого компьютера.");
        return 0;
    }
    else return 1;
}

varargs mixed eventUninstallModule(object which, int auto){
    object *contents = all_inventory();
    object module = previous_object();
    if(which) module = which;
    if(!auto) say(this_player()->GetName()+" использует "+possessive(this_player())+" "
            "переносной компьютер.");
    if(!active){
        if(!auto) write("Компьютер не активен.");
        return 1;
    }
    if(!auto){
        write("Вы пытаетесь извлечь модуль из переносного компьютера. Появляется сообщение:");
        say(this_player()->GetName()+" появляется сообщение из переносного компьютера: ");
        yaut_say("Uninstalling...");
    }
    if(SpecialFuns[module])
        foreach(mixed key, mixed val in SpecialFuns[module]){
            remove_action("foo",SpecialFuns[module][key]["hook"]);
            if(!auto){
                yaut_say(key+" successfully uninstalled.");
            }
        }
    map_delete(SpecialFuns, module);
    return 1;
}

varargs mixed eventInstallModule(mapping ModuleData, int auto){
    string *contents = ({});
    object module = previous_object();
    if(member_array("eventInitialize",call_stack(2)) != -1) auto = 1;
    if(!auto) say(this_player()->GetName()+" использует "+possessive(this_player())+" "
            "переносной компьютер.");
    if(!answers_to("Информационный модуль",module)){
        if(!auto) write("Это не подходящий информационный модуль для этого компьютера.");
        return 0;
    }
    if(!active){
        if(!auto) write("Компьютер не активен..");
        return 1;
    }
    if(this_object()->GetClosed()){
        write("Компьютер закрыт.");
        return 1;
    }
    if(sizeof(all_inventory()))
        foreach(object element in all_inventory()){
            contents += ({ base_name(element) });
        }
    if(member_array(base_name(module),contents) != -1){
        if(!auto){
            write("Переносной компьютер уже содержит этот модуль.");
            return 0;
        }
    }
    SpecialFuns[module] = ModuleData;
    if(!auto){ 
        write("Вы устанавливаете модуль в переносной компьютер. Появляется информация:");
        say(this_player()->GetName()+" из переносного компьютера появляется информация: ");
        yaut_say("Installing...");
    }
    foreach(mixed key, mixed val in SpecialFuns[module]){
        add_action(SpecialFuns[module][key]["function"],SpecialFuns[module][key]["hook"]);
        if(!auto){ 
            yaut_say(key+" successfully installed.");
            module->eventMove(this_object());
        }
    }
    return 1;
}

mixed CanPutInto(object who, object item){
    return "Это переносной компьютер. Вы можете установить в него модули.";
}

mixed CanGetFrom(object who, object item){
    return "Это переносной компьютер. Из него можно удалить модули.";
}

varargs mixed eventRead(mixed who, mixed str){
    object dude;
    string what;
    string ret = "Информационный дисплей. Установленные модули:\n";
    if(stringp(who)){
        what = who;
        dude = this_player();
    }
    else {
        dude = who;
        what = str;
    }
    if(this_object()->GetClosed()){
        write("Переносной компьютер закрыт. Вы не можете ничего на нем прочесть.");
        return 1;
    }
    if(!active){
        write("Переносной компьютер не активен.");
        return 1;
    }
    foreach(mixed ob in all_inventory()){
        if(ob->Report()) ret += ob->Report();
    }
    if(!lupus && random(99) > 95){
        lupus = 1;
        ret = "BAD WOLF";
    }
    SetRead( ([
                ({ "panel", "default" }) :ret,
                ]) );
    return ::eventRead(dude, what);
}

varargs mixed eventOpen(object who, object tool){
    SetProtection(BLUNT, 1);
    SetProtection(BLADE, 1);
    SetProtection(KNIFE, 2);
    SetProtection(HEAT, 3);
    ::eventOpen(who || 0, tool || 0);
    if(!(this_object()->GetClosed())){
        write("При открытии переносного компьютера вам стала доступна информационная панель.");
        return 1;
    }
    return 0;
}

mixed eventClose(object who){
    SetProtection(BLUNT, 10);
    SetProtection(BLADE, 10);
    SetProtection(KNIFE, 20);
    SetProtection(HEAT, 30);
    return ::eventClose(who || 0);
}

string GetInternalDesc(){
    return "Это интерфейс переносного компьютера. Вы можете попытаться \"read computer\"";
}

varargs mixed eventUnequip(object who){
    object *contents = all_inventory();
    if(sizeof(contents)) contents->eventPowerOff();
    ::eventUnequip(who||0);
}
