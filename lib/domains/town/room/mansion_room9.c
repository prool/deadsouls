#include <lib.h>
inherit LIB_ROOM;

int revealed;
int PreExit(){
    object ob = present("вор в полотенце",this_object());
    if(ob && base_name(ob) != "/lib/std/corpse"){
        write("Что-то преградило вам дорогу!");
        return 0;
    }
    return 1;
}
static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Гостиная");
    SetLong("Вы находитесь в роскошной гостиной, украшенной  "
            "и обставленной с таким же отличным вкусом и вниманием  "
            "к деталям, как и остальная часть "
            "особняка.");
    SetItems( ([
                ({"мебель","обстановка","украшения"}) :
                "Тут все свидетельствует об утонченном "
                "эстетическом чувстве."
                ]) );
    SetExits( ([
                "west" : "/domains/town/room/mansion_int.c",
                ]) );
    SetInventory( ([
                "/domains/town/obj/rug" :1,
                "/domains/town/npc/thief" :1
                ]) );
    revealed = 0;
}
int TellRevealed(){
    if(revealed) return revealed;
    else return 0;
}
int RevealDoor(){
    if(revealed == 1) {
        tell_room(this_object(),"Потайная дверь уже видна.");	
        return 1;
    }
    revealed = 1;

    tell_room(this_object(),"Вы обнаружили потайную дверь!");
    AddExit("down","/domains/town/room/mansion_room12", (: PreExit :));
    SetDoor("down","/domains/town/doors/trapdoor");
    return 1;
}
void init(){
    ::init();
}
