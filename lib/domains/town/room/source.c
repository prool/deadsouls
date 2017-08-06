#include <lib.h>
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(0);
    SetShort("Темный туннель");
    SetLong("У этого ведущего на восток туннеля очень гладкие стены. В его потолке вы завечаете ведущий наружу люк.");
    SetItems(([
                ({ "люк", "отверстие", "потолок" }) : "Кажется, что люк образовался естественным образом, в результате движения подземных вод. ",
                ({ "грязь", "пыль" }) : "Этого здесь полно, вряд ли сюда приходит уборщик.",
                ({ "дно", "колодец" }) : "Грязный, затхлый и неприятный.",
                ({ "паразиты", "крысы", "насекомые" }) : "Кажется, они попрятались сейчас от вас.",
                "убежище" : "Отличное место для паразитов.",
                ({ "скала", "порода" }) : "Это плотный, тяжелый материал глубоко под землей.",
                ]));
    SetFlowLimit(40);
    SetInventory( ([
                "/domains/town/obj/water_pipe" : 1,
                "/domains/town/obj/waterwheel" : 1,
                ]) );
    SetExits( ([
                "up" : "/domains/town/room/well3",
                "east" : "/domains/town/room/wtunnel2.c",
                ]) );

    SetDoor("up", "/domains/town/doors/grate.c");

}
void init(){
    ::init();
}
