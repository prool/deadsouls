#include <lib.h>

inherit LIB_ROOM;

static void create() {
    object ob;
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Проход к зверинцу");
    SetLong("Этот небольшой проход ведет вниз, к зверинцу. Его магические свойства препятствуют проходы NPC, поэтому существа внизу не могут сбежать. А на севере вы видите главный коридор.");
    SetExits( ([
                "north" : "/domains/default/room/wiz_corr_east",
                "down" : "/domains/default/room/menagerie.c",
                ]) );

    SetInventory(([
                ]));

}
int CanReceive(object ob) {
    //if(living(ob) && !creatorp(ob) && !present("testchar badge",ob)) {
    //	message("info","Creator staff only, sorry.", ob);
    //	return 0;
    //   }
    if(living(ob) && !interactive(ob)){
        message("info","NPC здесь не позволены, извините.", ob);
        return 0;
    }
    return room::CanReceive(ob);
}

void init(){
    ::init();
}
