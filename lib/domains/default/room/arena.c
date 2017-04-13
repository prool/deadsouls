#include <lib.h>
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Арена");
    SetLong("Вы находитесь в большой комнате с пустыми цементными стенами. Она была создана для того, чтобы билдеры могли потестить оружие, броню или мобов в бою. Также вы видите здесь прочную стальную дверь, препятствующую побегу трусливых созданий.");
    SetItems( ([
                ({"стена","стены"}) : "Стены гладкие и прочные, кое где забрызганы кровью.",
                ({"потолок","пол"}) : "Пол и потолок тоже цементные, "+
                "как и стены." ]) );
    SetInventory(([
                "/domains/default/npc/fighter" : 1,
                "/domains/default/obj/locker" : 1,
                "/domains/default/npc/dummy" : 1,
                "/domains/default/obj/case" : 1,
                "/domains/default/obj/abox" : 1,
                "/domains/default/obj/javelin_bin" : 1,
                "/domains/default/obj/rack" : 1,
                ]));
    SetExits( ([ 
                "south" : "/domains/default/room/wiz_corr_east",
                ]) );
    SetPlayerKill(1);

    SetDoor("south", "/domains/default/doors/steel_door2.c");

}

int CanReceive(object sneak) {
    object *living_stack = get_livings(sneak);
    if(!living_stack || !arrayp(living_stack)) living_stack = ({ sneak });
    foreach(object ob in living_stack){
        if(playerp(ob) && !creatorp(ob) &&
                !member_group(ob,"TEST")) {
            message("info","Извините, но эта вещь только для билдеров.", ob);
            return 0;
        }
    }
    return 1;
}

void init(){
    ::init();
}
