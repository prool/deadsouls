#include <lib.h>
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(0);
    SetShort("Темный туннель");
    SetLong("Стены этого ведущего с запада на восток туннеля сглажены потоками воды.");
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
                "west" : "/domains/town/room/source",
                "east" : "/domains/town/room/wtunnel3.c",
                ]) );

    SetDoor("east", "/domains/town/doors/pressure_door.c");

}
void init(){
    ::init();
}
