#include <lib.h>
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Конюшни");
    SetLong("Вы зашли в местные конюшни, где жители города оставляют своих лошадей на попечение Ингрид. Хотя тут немного воняет, в конюшнях царит чистота и порядок.");
    SetItems(([
                ({ "здание", "здания" }) : "В этих сооружениях живут люди.",
                ]));
    SetProperties(([
                "no attack" : 1,
                ]));
    SetInventory(([
                "/domains/town/npc/ingrid" : 1,
                "/domains/town/npc/horse" : 1,
                ]));
    SetExits(([
                "north" : "/domains/town/room/vill_road4",
                ]));

    SetEnters( ([ 
                ]) );

}
void init(){
    ::init();
}
