#include <lib.h>
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(0);
    SetShort("Темный туннель");
    SetLong("Стены этого ведущего с юга на северо-восток в пещеру туннеля сглажены потоками воды.");
    SetItems(([
    SetItems(([
                ({ "дыра", "пол" }) : "Через это отверстие поступает из подземного источника питающая колодец вода. ",
                ({ "грязь", "пыль" }) : "Здесь этого полно. Уборка тут бы не помешала.",
                ({ "дно", "колодец" }) : "Тут грязно, сыро и неприятно.",
                ({ "паразиты", "крысы", "насекомые" }) : "Похоже, что они сейчас от вас попрятались.",
                ({ "скала", "порода" }) : "Скала очень плотная и прочная, пробить такую не просто.",
                ]));
    SetFlowLimit(3);
    SetExits( ([
                "south" : "/domains/town/room/wtunnel5",
                "northeast" : "/domains/cave/room/cavetroll.c",
                ]) );

    SetDoor("northeast", "/domains/town/doors/gate.c");

}
void init(){
    ::init();
}
