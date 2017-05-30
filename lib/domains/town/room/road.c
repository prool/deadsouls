#include <terrain_types.h>
#include <lib.h>
inherit LIB_ROOM;
static void create() {
    room::create();
    SetClimate("outdoors");
    SetAmbientLight(30);
    SetShort("Северная дорога");
    SetNightLong("Освещенная лампами дорога тянется через город с юга с центрального перекрестка на север во мрак. На востоке находится местный бар - пристанище сотен воров и авантюристов. На западе вы видите вывеску гильдии целителей.");
    SetDayLong("Эта дорога тянется через весь город с юга с центрального перекрестка на север к плато с огромной крепостью. На востоке находится местный бар - пристанище сотен воров и авантюристов. На западе вы видите вывеску гильдии целителей.");
    SetItems( ([
        ({"бар","таверна","пивная"}) : "Здесь можно "
        "упиться насмерть.",
        ({"гильдия","гильдия целителей"}) : "В этом здании "
        "находится единственный лекарь в городе.",
        "облака" : "Маленькие пухлые облака "
        "окружают пики северных гор.",
        ({"северные горы","горы","гора","горная цепь"}): 
        "Вы видите величественные горы далеко на севере, "
        "со сверкающими снежными шапками.",
        "перекресток" : "Центральный перекресток города находится на юге."
      ]) );
    SetSkyDomain("town");
    SetInventory(([
        "/domains/town/weap/knife" : 1,
      ]));
    SetExits( ([
        "north" : "/domains/town/room/mountain_road",
        "east" : "/domains/town/room/tavern",
        "west" : "/domains/town/room/healer",
        "south" : "/domains/town/room/road0.c",
      ]) );
    AddTerrainType(T_ROAD);

    SetEnters( ([
        "pub" : "/domains/town/room/tavern",
        "guild" : "/domains/town/room/healer",
        "healers guild" : "/domains/town/room/healer"
      ]) );
    SetNoModify(0);
    AddItem(new("/domains/town/obj/lamp"));
}

void init(){
    ::init();
}
