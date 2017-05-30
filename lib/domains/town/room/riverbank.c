#include <lib.h>
inherit LIB_FISHING;

static void create() {
    ::create();
    SetTown("town");
    SetClimate("temperate");
    SetAmbientLight(30);
    SetShort("Берег реки");
    SetLong("Вы на берегу узкой, но стремительно бегущей реки. Крутой путь наверх ведет к мосту. А, в отвесной восточной стене берега вы замечаете вход в пещеру.");
    SetProperties (([
                "no attack":0, 
                "no bump":0, 
                "no steal":0, 
                "no magic":0, 
                "no paralyze":0, 
                "no teleport":0]));
    SetListen(([
                ({ "река", "вода" }) : "Вы слышите, как она проносится мимо.",
                "default" : "Вы можете услышать рев реки, текущей мимо.",
                ]));
    SetInventory(([
                "/domains/town/npc/troll" : 1,
                "/domains/town/obj/rocks" : 1,
                "/domains/town/obj/riverwater" : 1,
                ]));
    AddExit("up", "/domains/town/room/bridge");
    if(unguarded( (: file_exists("/domains/cave/room/cave.c") :) ) ){
        AddExit("east", "/domains/cave/room/cave");
    }
    SetChance(90);
    SetFish( ([
                "/domains/town/meals/shark" : 10,
                ]) );
}
void init() {
    ::init();
    SetSmell(([]));
}

int CanReceive(object ob){
    if(answers_to("provost",ob)) return 0;
    return ::CanReceive();
}
