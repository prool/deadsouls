#include <terrain_types.h>
#include <lib.h>
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("outdoors");
    SetAmbientLight(30);
    SetShort("Мощеная дорога");
    SetLong("Вы находитесь на мощеной дороге ведущей "+
      "на север в город. "+
      "На западе вы замечаете "+
      "магический магазин. "+
      "\n%^GREEN%^Рядом с дорогой стоит "+
      "старый колодец.%^RESET%^");
    SetItems( ([
        ({"колодец","старый колодец","высохший колодец"}) : "Похоже, "
        "что его раньше использовали для добычи воды, "
        "пока в городе не сделали более современное "
        "водоснабжение. Он выглядит высохшим и заброшенным "
        "длительное время.",
        "банк" : "Первый Деревенский банк",
        ({"дорога","мощеная дорога"}) : "Мощеная дорога "
        "ведет прямо с севера на юг."
      ]) );
    SetSkyDomain("town");
    SetExits( ([ 
        "north" : "/domains/town/room/start",
        "west" : "/domains/town/room/magic_shop",
      ]) );
    if(strsrch(mud_name(), "Dead Souls")){
        //AddExit("south", "/domains/campus/room/south_road2");
    }
    AddTerrainType(T_ROAD);
    SetNoModify(0);
    SetEnters( ([
        "well" : "/domains/town/room/well1"
      ]) );
    AddItem(new("/domains/town/obj/lamp"));
}
void init(){
    room::init();
}
