#include <lib.h>
#include ROOMS_H

inherit LIB_ROOM;

void create() {
    room::create();
    SetAmbientLight(30);
    SetShort("Зверинец, восток");
    SetLong("Это восточная часть зверинца.");
    SetInventory(([
                "/domains/default/npc/foochy" : 1,
                "/domains/default/npc/satyr" : 1,
                "/domains/default/npc/slug" : 1,
                "/domains/default/npc/unicorn" : 1,
                "/domains/default/npc/triffid" : 1,
                "/domains/default/npc/snake" : 1,
                "/domains/default/npc/sheep" : 1,
                "/domains/default/npc/boar" : 1,
                "/domains/default/npc/pegasus" : 1,
                "/domains/default/npc/giant" : 1,
                "/domains/default/npc/lemur" : 1,
                "/domains/default/npc/treant" : 1,
                ]));
    SetExits(([
                "west" : "/domains/default/room/menagerie",
                ]));

}
void init(){
    ::init();
}
