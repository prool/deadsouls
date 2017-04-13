#include <lib.h>
#include ROOMS_H

inherit LIB_ROOM;
int ds;

static void create() {
    object ob;
    room::create();
    if(mud_name() == "Dead Souls"){
        ds = 1;
    }
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Верхняя часть зала билдеров");
    SetLong("Это верхняя часть зала билдеров. На востоке находится узел связи с создателями этого мада. На юге части мира, которые вы можете посетить. Основной зал ниже.");
    SetProperty("no attack", 1);
    SetProperty("nopeer",1);
    ob = new("/lib/bboard");
    ob->SetKeyName("доска объявлений");
    ob->SetId( ({ "доска", "доска объявлений", "объявлений", "объявления" }) );
    ob->set_board_id("immortal_board");
    ob->set_max_posts(30);
    SetShort("Залы билдеров, западное крыло");
    ob->eventMove(this_object());
    SetItems( ([
                ({"знак"}) : "На знаке что-то написано.",
                ]) );
    SetExits( ([
                "south" : "/domains/default/room/domains_room",
                "down" : "/domains/default/room/wiz_hall",
                "east" : "/domains/default/room/telnet_room.c",
                ]) );
    if(!ds){
    }
    SetInventory(([
                ]));

    SetRead("знак", (: load_object(ROOM_ARCH)->SignRead() :) );
}

int CanReceive(object ob) {
    if(playerp(ob) && !creatorp(ob) &&
            !member_group(ob,"TEST")) {
        message("info","Извините, но эта вещь только для билдеров.", ob);
        return 0;
    }

    if(ob->GetRace() == "rodent"){
        message("info","You are repelled by rodenticide.",ob);
        return 0;
    }
    return 1;
}
void init(){
    ::init();
}
