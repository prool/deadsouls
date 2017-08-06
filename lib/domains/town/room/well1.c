#include <lib.h>
inherit LIB_ROOM;
int humidity = 0;

string GetDryDesc(){
    string ret = "Вы находитесь на дне старого городского колодца. Здесь царят "+
        "кромешный мрак и сырость. Годы запустения позволили тут размножиться "+
        "насекомым, грязи и пыли. В западной стене вы замечаете дверь - "+
        "служебный выход отсюда.\n%^GREEN%^Рядом с дверью вы замечаете также рычаг."+
        "%^RESET%^";
    return ret;
}

string GetWetDesc(){
    string ret = "Вы находитесь на дне старого городского колодца. Здесь царят "+
        "кромешный мрак и сырость. В западной стене вы замечаете дверь - "+
        "служебный выход отсюда.\n%^GREEN%^Рядом с дверью вы замечаете также рычаг."+
        "%^RESET%^";
    return ret;
}

string GetWellDesc(){
    string ret;
    if(humidity) ret = GetWetDesc();
    else ret = GetDryDesc();
    return ret;
}

static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(0);
    SetShort("Городской колодец");
    SetLong( (: GetWellDesc :) );
    SetItems( ([
                ({ "дно","колодец" }) : "Тут грязно, сыро "
                "и мерзко.",
                "haven" : "A nice place for vermin.",
                ({"грязь","пыль"}) : "Здесь этого предостаточно."
                "Похоже, пустые колодцы не так уж часто "
                "чистят.",
                ({"паразиты","крысы","насекомые"}) : "При вашем "
                "виде они разбежались и попрятались "
                "по углам."
                ]) );
    SetInventory(([
                "/domains/town/obj/well_lever" : 1,
                ]));
    SetExits( ([ 
                "up" : "/domains/town/room/south_road1",
                "west" : "/domains/town/room/well2",
                ]) );
    SetDoor("west", "/domains/town/doors/welldoor1.c");
    SetFlowLimit(1);
}

void init(){
    ::init();
}

int eventCompleteQuest(object ob){
    string *quests;
    quests = ob->GetQuests();
    if(ob && !ob->GetQuest("Задание в городском колодце")){
        ob->AddQuest("Водопроводчик","Задание в городском колодце");
        tell_player(ob, "%^BOLD%^%^RED%^Вы разгадали задание в городском колодце.");
        tell_player(ob, "%^BOLD%^%^RED%^Поздравляем!");
        tell_player(ob, "%^BOLD%^%^RED%^Вы получаете 7 квестовых очков и "+
                "1500 очков опыта.");
        ob->AddQuestPoints(7);
        ob->AddExperiencePoints(1500);
    }
    return 1;
}

int eventReceiveObject(object ob){
    if(base_name(ob) == LIB_FLOW && !humidity){
        object player;
        mixed wheel = objects((: base_name($1) ==
                    "/domains/town/obj/waterwheel" && clonep($1) :));
        if(sizeof(wheel)) wheel = wheel[0];
        if(objectp(wheel)) player = wheel->GetTurner();
        if(player) eventCompleteQuest(player);
        humidity = 1;
        SetItems(([]));
    }
    return ::eventReceiveObject(ob);
}
