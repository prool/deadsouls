#include <lib.h>
#include ROOMS_H

inherit LIB_ROOM;

static void create() {
    object ob;
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Зал билдеров");
    SetLong("В этом комфортабельном помещении билдеры могут обсудить свою работу и оставить сообщения друг другу на доске объявлений. На севере вы замечаете гильдию искателей приключений.");
    SetProperty("no attack", 1);
    SetProperty("nopeer",1);
    ob = new("/lib/bboard");
    ob->SetKeyName("доска объявлений");
    ob->SetId( ({ "доска", "доска объявлений", "объявлений" }) );
    ob->set_board_id("builder_board");
    ob->set_max_posts(30);
    ob->SetShort("доска объявлений");
    ob->eventMove(this_object());
    SetItems( ([
                ({"знак"}) : "Знак который можно прочесть.",
                ]) );
    SetExits( ([ 
                "north" : "/domains/town/room/adv_guild",
                ]) );
    SetInventory(([
                "/domains/default/obj/couch" : 1,
                ]));
}

int CanReceive(object sneak) {
    object *living_stack = get_livings(sneak);
    if(!living_stack || !arrayp(living_stack)) living_stack = ({ sneak });
    foreach(object ob in living_stack){
        if(playerp(ob) && !builderp(ob) && !present("testchar badge",ob) &&
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
