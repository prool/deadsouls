#include <lib.h>
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Игровая комната");
    SetLong("Вы в игровой комнате. Стены здесь обшиты "
      "панелями из красного дуба, а толстые ковры "
      "под ногами создают ощущение уюта.");
    SetItems( ([
        ({"стена","стены"}) : "Вы видите красивую дубовую "
        "обшивку приятного цвета.",
        ({"ковер","ковры"}) : "Они очень мягкие и "
        "комфортабельные."
      ]) );
    AddStuff( ({
        "/domains/town/obj/btable",
        "/domains/town/obj/pool_table"
      }) );
    SetExits( ([
        "east" : "/domains/town/room/mansion_uhall2"
      ]) );

    SetDoor("east", "/domains/town/doors/m4.c");

}
void init(){
    ::init();
}
