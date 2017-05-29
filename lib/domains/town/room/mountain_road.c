#include <terrain_types.h>
#include <lib.h>
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("outdoors");
    SetAmbientLight(30);
    SetShort("Дорога к крепости");
    SetNightLong("Вы находитесь на дороге, ведущей на север от города. На востоке вы видите вывеску местного банка, а на западе здание почты.");
    SetDayLong("Вы находитесь на дороге, ведущей на север от города к мрачной крепости. На востоке вы видите вывеску местного банка, а на западе здание почты.");
    SetItems( ([
        ({"дорога"}) : "Похоже, что "
        "дорога еще не достроена. Дальнейшее путешествие на север "
        "невозможно.",
        ({"горы","гора"}) : "Горизонт на севере "
        "закрывают величественные горы со снежными шапками."
      ]) );
    SetSkyDomain("town");
    SetExits( ([
        "south" : "/domains/town/room/road",
        "east" : "/domains/town/room/bank",
        "west" : "/domains/town/room/postoffice.c",
      ]) );
    if(!strsrch(mud_name(), "Dead Souls")){
        if(directory_exists("/domains/fort")){
            AddExit("north", "/domains/fort/room/f_road4");
        }
    }
    AddTerrainType(T_ROAD);
    AddItem(new("/domains/town/obj/lamp"));
    if(file_exists("/domains/fort/room/f_road4.c")){
    }
}
void init(){
    ::init();
}
