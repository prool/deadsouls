#include <terrain_types.h>
#include <lib.h>
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("outdoors");
    SetAmbientLight(30);
    SetShort("Грязная дорога");
    SetNightLong("Слабо освещенная лампой дорога здесь переходит в самую обычную грязную тропу. На востоке отсюда видно побережье, а на севере здание школы. То, что напоминает конюшни, находится на юге.");
    SetDayLong("Здесь ведущая из города дорога переходит в самую обычную грязную тропу. На востоке отсюда видно побережье, а на севере здание школы. То, что напоминает конюшни, находится на юге.");
    SetItems(([
        ({ "здание", "здание школы", "школа", "village school", "village schoolhouse" }) : "Вероятно там местные жители и их дети получают знания.",
        ({ "здания", "строения" }) : "Там обитают люди.",
        ({ "берег", "побережье" }) : "Побережье восточного моря к востоку отсюда.",
      ]));
    SetSkyDomain("town");
    AddTerrainType(T_ROAD);
    SetExits( ([
        "west" : "/domains/town/room/vill_road3",
        "north" : "/domains/town/room/school",
        "east" : "/domains/town/room/shore",
        "south" : "/domains/town/room/stables.c",
      ]) );
    SetEnters( ([ 
      ]) );
    AddItem(new("/domains/town/obj/lamp"));
}
void init(){
    ::init();
}
