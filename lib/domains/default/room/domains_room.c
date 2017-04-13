#include <lib.h>
#include ROOMS_H

inherit LIB_ROOM;

string LongDesc(){
    string desc = "Бессмертные приходят сюда чтобы посетить "+
        "созданный ими мир. Зал билдеров находится выше. "+
        "Чтобы посетить "+
        "тестовую комнату, идите на запад.";
    return desc;
}

static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Перекресток миров");
    SetLong("Из этого места вы можете попасть в различные части этого мира.");
    SetItems(([
                "кампус" : "Это точка входа в зону кампус.",
                "примеры" : "Это точка входа в зону примеров.",
                "город" : "Это точка входа в зону город.",
                "пещера" : "Это точка входа в зону пещера.",
                "обучение" : "Это точка входа в обучающую зону.",
                ({ "знак" }) : "Знак который можно прочесть.",
                ]));
    SetEnters( ([
                "кампус" : "/domains/campus/room/start",
                "примеры" : "/domains/examples/room/start.c",
                "пещера" : "/domains/cave/room/start",
                "город" : "/domains/town/room/start",
                "обучение" : "/domains/learning/room/start",
                ]) );
    SetProperty("no attack", 1);
    SetProperty("nopeer",1);
    SetExits(([
                "north" : "/domains/default/room/wiz_hall2",
                ]));

    SetInventory(([
                ]));

    SetRead("знак", (: load_object(ROOM_ARCH)->SignRead() :) );
}

int CanReceive(object ob) {
    if(playerp(ob) && !creatorp(ob) && !present("testchar badge",ob) &&
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
