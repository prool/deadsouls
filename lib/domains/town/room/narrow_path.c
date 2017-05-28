#include <lib.h>
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("outdoors");
    SetAmbientLight(30);
    SetShort("Узкая тропа");
    SetLong("Эта узкая тропка ведет на северо-восток к зеленой долине и на юг к густому лесу. Плотная растительность по сторонам не дает сойти с этого пути.");
    SetItems(([
        ({ "тропа", "путь" }) : "Вы стоите на узкой тропе и со всех сторон вас обступают мрачные деревья.",
        ({ "лес", "деревья", "растительность" }) : "Вокруг растет растительность, настолько невероятно плотная, что невозможно сбиться с пути.",
      ]));
    SetSkyDomain("town");
    SetExits( ([
        "northeast" : "/domains/town/room/valley",
        "south" : "/domains/town/room/narrow_path2.c",
      ]) );
    SetInventory(([
      ]));

}
void init(){
    ::init();
}

int CanReceive(object ob){
    if(answers_to("provost",ob)) return 0;
    return ::CanReceive();
}
