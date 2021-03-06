#include <lib.h>
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(0);
    SetShort("Высохший источник");
    SetLong("Похоже, что эта маленькая темная камера была вырезана в скале. В центре помещения вы замечаете высверленное отверстие, откуда поступает вода. Учитывая твердость окружающих пород, сооружение этого источника потребовало кучи сил и людей. Выйти отсюда можно через дверь на востоке.");
    SetItems(([
                ({ "дыра", "пол" }) : "Через это отверстие поступает из подземного источника питающая колодец вода. ",
                ({ "грязь", "пыль" }) : "Здесь этого полно. Уборка тут бы не помешала.",
                ({ "дно", "колодец" }) : "Тут грязно, сыро и неприятно.",
                ({ "паразиты", "крысы", "насекомые" }) : "Похоже, что они сейчас от вас попрятались.",
                ({ "скала", "порода" }) : "Скала очень плотная и прочная, пробить такую не просто.",
                ]));
    SetFlowLimit(3);
    SetExits( ([
                "east" : "/domains/town/room/well2",
                "down" : "/domains/town/room/source.c",
                ]) );
    SetDoor("east", "/domains/town/doors/welldoor2.c");

    SetDoor("down", "/domains/town/doors/grate.c");

}
void init(){
    ::init();
}
