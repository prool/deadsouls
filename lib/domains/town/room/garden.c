#include <lib.h>
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("outdoors");
    SetAmbientLight(30);
    SetNightLight(10);
    SetDayLight(30);
    SetShort("Сад особняка");
    SetLong("Это все, что осталось от некогда красивого "
      "сада. Теперь он сильно зарос сорняками, а дикие "
      "животные сожрали изысканные цветы и декоративные овощи, "
      "которые росли здесь раньше. "
      "На севере вы замечаете лачугу садовника.");
    SetItems(([
        ({ "цветы", "овощи", "цветы и овощи" }) : "Хотя они росли здесь раньше, сейчас от них ничего не осталось.",
        ({ "лачуга", "деревянная лачуга" }) : "На севере находится полуразвалившаяся деревянная лачуга.",
        "сад" : "Он весь зарос сорняками.",
      ]));
    SetSkyDomain("town");
    SetExits( ([
        "east" : "/domains/town/room/mansion_ext",
        "north" : "/domains/town/room/shack"
      ]));
    SetEnters( ([
        "shack" : "/domains/town/room/shack",
      ]) );
}
void init(){
    ::init();
}
