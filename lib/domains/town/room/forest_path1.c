#include <lib.h>
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("outdoors");
    SetAmbientLight(30);
    SetNightLight(10);
    SetDayLight(30);
    SetShort("Лесная тропа");
    SetLong("Вы находитесь в лесу за городом. На юго-западе она ведет к поляне, а на востоке к мосту у города. На юге путь преграждает густая поросль из деревьев и кустарников, но на севере вы видите небольшие просветы между ними.");
    SetItems( ([
        "лес" : "Вы находитесь на тропе в темном мрачном лесу. "
        "Густая растительность вокруг выглядит как-то угнетающе.",
        ({"растения","кустарники","растительность","дерево","деревья","куст"}) : 
        "Растения, кустарники и деревья растут тут очень густо "
        "и ограничивают видимость за пределами тропы.",
        "мост" : "Вы видите старый мост на востоке.",
        "поляна" : "На западе вы видите просвет среди деревьев. "
        "Вероятно это лесная поляна.",
        "тропа" : "Вы остановились на тропе посреди леса."
      ]) );
    SetSkyDomain("town");
    SetExits( ([
        "north" : "/domains/town/virtual/forest/-4,1",
        "east" : "/domains/town/room/bridge",
        "southwest" : "/domains/town/room/clearing.c",
      ]) );
}
void init(){
    ::init();
}

int CanReceive(object ob){
    object env = environment(ob);
    if(!env || base_name(env) != "/domains/town/virtual/forest/24,1"){
        return ::CanReceive();
    }
    if(living(ob) && !interactive(ob) &&
      (!ob->GetRiders() || !sizeof(ob->GetRiders()))){
        ob->eventPrint("Почему-то вы не можете покинуть этот лес.");
        return 0;
    }
    return ::CanReceive();
}
