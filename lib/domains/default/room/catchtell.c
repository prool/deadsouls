#include <lib.h>
#include <daemons.h>
inherit LIB_ROOM;

static void create() {
    object ob;
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("catch_tell комната");
    SetLong("Эта комната предназначена для приема сообщений от NPC. Нужна в основном для отладки мада.");
    SetExits(([
                "west" : "/secure/room/network",
                ]));

}
int CanReceive(object ob) {
    if( !archp(ob) ){
        message("info","Комната catch tell доступна только для администраторов, "+
                "просим прощения.",ob);
        return 0;
    }
    return 1;
}
void init(){
    ::init();
}
