#include <lib.h>
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(15);
    SetShort("Орочья крепость");
    SetLong("Вы находитесь внутри орочьей крепости. Все вокруг выглядит очень грубо и устрашающе. В этой части крепости находится что-то вроде храма или святилища. В центре помещения стоит окровавленный алтарь, а у стен вы видите груды черепов. Выход отсюда находится на востоке.");
    SetItems(([
                ({ "череп","черепа" }) : "Некоторые черепа вам известны, "+
                "но большинство из них принадлежало непонятно кому. "+
                "Здесь есть как минимум один человеческий череп. Некоторые из "+
                "них совсем свежие, на них видны клочья кожи..",
                ({"святилище","церемониальная","храм"}) : "Здесь "+
                "проводятся орочьи ритуалы.",
                ({"кровь","окровавленный"}) : "Вокруг алтаря заметны "+
                "пятна высохшей крови. Видимо здесь орки проводят обряды "+
                "жертвоприношения.",
                ({"стена","стены"}) : "Стены сложены из неотесанного дерева, а зазоры между ними замазаны землей.",
                ]) );
    SetExits( ([ 
                "east" : "/domains/town/room/orc_fortress",
                ]) );
    SetSmell( ([ "default" : "Здесь витает зловоние мусора и экскрементов животных."]) );
    SetInventory(([
                "/domains/town/obj/altar" : 1,
                "/domains/town/npc/orc_shaman" : 1,
                ]));

}
void init(){
    ::init();
}
