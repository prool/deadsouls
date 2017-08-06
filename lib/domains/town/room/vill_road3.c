#include <terrain_types.h>
#include <lib.h>
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("outdoors");
    SetAmbientLight(30);
    SetShort("Восточная дорога");
    SetNightLong("Вы находитесь на освещенной лампой дороге, проходящей через город. На севере вы замечаете ратушу. Основная часть города находится к западу отсюда.");
    SetDayLong("Вы находитесь на длинной дороге, проходящей через город. На севере вы замечаете ратушу. Основная часть города находится к западу отсюда.");
    SetItems(([
        ({ "офис", "почта" }) : "На почте можно отправить или получить сообщение.",
        ({ "здание", "здания" }) : "В них обитают люди.",
        ({ "ратуша", "городская ратуша" }) : "Из этого места управляют городом и решают важные вопросы местных жителей.",
      ]));
    SetSkyDomain("town");
    SetExits( ([ 
        "north" : "/domains/town/room/thall",
        "east" : "/domains/town/room/vill_road4",
        "west" : "/domains/town/room/vill_road2",
      ]) );
    AddTerrainType(T_ROAD);
    AddItem(new("/domains/town/obj/lamp"));
}
void init(){
    ::init();
}
