#include <lib.h>

inherit LIB_ROOM;

static void create() {
    object ob;
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Зверинец");
    SetLong("В этих магических помещениях содержатся представители различных "
            "рас, доступные для билдеров в их зонах. Обычно эти создания "
            "не соседствуют друг с другом, но мощная магия хранит их вместе, "
            "так чтобы вы могли тестировать и анализировать их. "
            "Еще больше существ вы сможете найти на юге, востоке и западе.");
    SetExits( ([ 
                "south" : "/domains/default/room/menagerie_south",
                "east" : "/domains/default/room/menagerie_e",
                "west" : "/domains/default/room/menagerie_w",
                "up" : "/domains/default/room/wiz_corr_south",
                ]) );
    SetInventory(([
                "/domains/default/npc/horse" : 1,
                "/domains/default/npc/bird" : 1,
                "/domains/default/npc/elephant" : 1,
                "/domains/default/npc/bat" : 1,
                "/domains/default/npc/newt" : 1,
                "/domains/default/npc/lynx" : 1,
                "/domains/default/npc/deer" : 1,
                "/domains/default/npc/spider" : 1,
                "/domains/default/npc/bear" : 1,
                "/domains/default/npc/dryad" : 1,
                "/domains/default/npc/rat" : 1,
                "/domains/default/npc/zookeeper" : 1,
                "/domains/default/npc/cow" : 1,
                "/domains/default/npc/centaur" : 1,
                "/domains/default/npc/gnome" : 1,
                "/domains/default/npc/moth" : 1,
                "/domains/default/npc/gecko" : 1,
                ]));

}
void init(){
    ::init();
}
