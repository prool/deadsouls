#include <lib.h>
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("outdoors");
    SetAmbientLight(30);
    SetShort("У крыльца");
    SetLong("Вы видите шаткое крыльцо старого дома и дверь внутрь на юге. На севере, напротив дома поляна в лесу и тропинка, ведущая вглубь леса.");
    SetItems(([
                ({ "лес", "деревья", "растительность" }) : "Растительность вокруг такая плотная, что невозможно сойти с тропы.",
                ({ "крыльцо", "шаткое крыльцо" }) : "Это деревянное крыльцо старого белого дома.",
                ({ "тропа", "путь" }) : "На севере вы видите тропу ведущую в глубь леса.",
                ({ "поляна", "просвет" }) : "Словно по волшебству деревья здесь раступились около дома.",
                ({ "дом", "белый дом", "старый дом" }) : "Дом выглядит заброшенным и очень старым, но вас все-равно не покидает ощущение, что его хозяева вот-вот готовы вернуться.",
                ]));
    SetInventory(([
                "/domains/town/obj/rocking_chair" : 2,
                ]));
    SetExits( ([
                "north" : "/domains/town/room/cratshack",
                "south" : "/domains/town/room/living_room.c",
                ]) );

    SetDoor("south", "/domains/town/doors/house_door.c");

}
void init(){
    ::init();
}
int CanReceive(object ob){
    if(answers_to("provost",ob)) return 0;
    return ::CanReceive();
}
