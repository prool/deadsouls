#include <lib.h>
#include ROOMS_H

inherit LIB_ROOM;

static void create() {
    object ob;
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Приемная лаборатории болезней");
    SetLong("Эта комната предназначена для восприпятствования распространения болезней, которые изучаются в комнате вниз по лестнице. Также здесь вы можете получить защитную маску, которая не позволит вам заразиться самому. Для инфицирования подопытных используйте медицинский трикордер. Чтобы вылечить их наберите 'update' для обновления комнаты. Подопытные ждут вас внизу.");
    SetExits( ([
                "south" : "/domains/default/room/wiz_corr1",
                "down" : "/domains/default/room/quarantine2.c",
                ]) );
    SetInventory(([
                "/domains/default/obj/collarchest" : 1,
                ]));

    SetProperty("no attack", 1);

}
int CanReceive(object ob) {
    object *inv;
    string taxonomy;

    if(inherits(LIB_GERM,ob)) return 0;

    inv = deep_inventory(ob);
    foreach(object thing in inv){
        if(inherits(LIB_GERM,thing)) {
            write("%^YELLOW%^Инфекция обнаружена в вашем теле! Она будет автоматически удалена.%^RESET%^");
            if(taxonomy = thing->GetGermName()) write("%^YELLOW%^Удаление: "+taxonomy+".%^RESET%^");
            thing->eventMove(ROOM_FURNACE);
        }
    }

    return room::CanReceive();
}

void init(){
    ::init();
}
