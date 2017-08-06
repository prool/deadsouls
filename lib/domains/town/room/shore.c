#include <lib.h>
#include <daemons.h>

inherit LIB_FISHING;

int ActionFunction(){
    object *cres, dude;
    if(!sizeof(get_livings(this_object()))) return 0;
    //The next line identifies creators in the room
    cres = filter(get_livings(this_object()), (: creatorp($1) :) );
    //The next line picks a living being here at random
    dude = get_random_living(this_object());
    if(!dude) return 0;
    if((RACES_D->GetNonMeatRace(dude->GetRace()))) return 0;
    //The next line makes that person sigh. Note that since
    //creators normally can't be forced by non-privileged objects,
    //only npc's and players will be affected.
    dude->eventForce("sigh");
    //The next line tells any creators present the identitiy of the
    //target of the previous action.
    if(!sizeof(cres)) return 0;
    //The action below is commented out because it confused people.
    //basically it tells creators about this function.
    //cres->eventPrint("%^YELLOW%^The ActionFunction activates. Dude is: "+
    //  identify(dude)+".%^RESET%^");
    return 1;
}

varargs string readSign() {
    string ret = "Внимание! Некоторые расы не могут плавать! "+
    "И если они прыгнут в море, то утонут!";
    return ret;
}

int ActionFunction2(){
    object *cres, dude;
    if(!sizeof(get_livings(this_object()))) return 0;
    cres = filter(get_livings(this_object()), (: creatorp($1) :) );
    dude = get_random_living(this_object());
    if(!dude) return 0;
    if((RACES_D->GetNonMeatRace(dude->GetRace()))) return 0;
    dude->eventForce("ponder");
    if(!sizeof(cres)) return 0;
    //The action below is commented out because it confused people.
    //basically it tells creators about this function.
    //cres->eventPrint("%^GREEN%^ActionFunction2 activates. Dude is: "+
    //  identify(dude)+".%^RESET%^");
    return 1;
}

static void create() {
    fishing::create();
    SetClimate("outdoors");
    SetAmbientLight(30);
    SetShort("Береговая линия");
    SetNightLong("Вы находитесь на берегу моря в восточной части города, туда ведет западная дорога. Эта часть берега освещена одиноким фонарным столбом. \n%^GREEN%^Здесь есть табличка, которую можно прочесть.%^RESET%^");
    SetDayLong("Вы находитесь на берегу моря в восточной части города, туда ведет западная дорога. С востока накатывают спокойные волны моря, простирающееся до горизонта. \n%^GREEN%^Здесь есть табличка, которую можно прочесть.%^RESET%^");
    SetItems( ([
        "табличка":"В землю воткнута табличка, чтобы прочитать ее попробуйте 'читать табличку'.",
        "земля":"Чистый белый песок.",
        "горизонт":"Оттуда каждое утро появляется солнце.",
        "город":"Город находится к западу отсюда.",
        "дорога":"Ведет на запад к городу.",
      ]) );
    SetExits( ([
        "west" : "/domains/town/room/vill_road4",
        "south" : "/domains/town/room/docks.c",
      ]) );
    SetRead("табличку", (: readSign :) );
    //SetFrequency determines how often the room checks 
    //whether it should perform an action. If it is set
    //at 1, it checks approximately every second. The
    //default is 5.
    SetFrequency(5);
    //The first argument of SetAction is a number, indicating from
    //one to 100 the percentage of likelihood an event will occur.
    //The second argument is an array that contains strings,
    //functions, or both. Every time an action is triggered, an
    //element is picked from the array at random. If it is a string,
    //that string is displayed to the living things in the room.
    //If it is a function, that function is evaluated.
    SetAction(2, ({"Холодный ветер дует с востока, "
        "донося до вас соленый запах моря.",
        (: ActionFunction :) }) );
    SetChance(90);
    SetFish( ([
        "/domains/town/meals/shark" : 1,
        "/domains/town/meals/herring" : 10,
      ]) );
    //This is a function that allows for a set of actions
    //with different trigger frequencies.
    SetActionsMap( ([ 
        "Холодный ветер дует вам в лицо." : 5,
        "Вы слышите резкие вскрики чаек вдали." : 7,
        (: ActionFunction2 :) : 2,
      ]) );
    SetInventory( ([
        "/domains/town/obj/seawater" : 1,
      ]) );
    AddItem(new("/domains/town/obj/lamp"));
    SetSkyDomain("town");
}
void init(){
    ::init();
}
