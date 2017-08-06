#include <lib.h>
inherit LIB_ROOM;

static void create() {
    ::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Местная таверна");
    SetLong("Вы зашли в местную таверну. Здесь вы можете заказать следующую выпивку и закуску:\n\n"+
            "\tПервоклассный эль:\t\t\t\t10 silver\n"
            "\tСамогон:\t\t\t\t20 silver\n"
            "\tГорилка:\t\t\t\t\t50 silver\n"
            "\tЧистая вода:\t\t\t\t\t2 silver\n"
            "\tОбычный кофе:\t\t\t\t\t5 silver\n"
            "\tИмпортный эспрессо:\t\t\t\t15 silver\n"
            "\tБутерброд с ветчиной:\t\t\t\t\t10 silver\n\n\n"
            "Чтобы купить бутылку воды, наберите \"купить воду у ларса\"\n"
            "\nНа стене вы замечаете портрет в рамке.\n"
           );
    SetItems(([
                ({ "портрет", "портрет в рамке", "картину", "картина" }) : "Вы видите картину с изображением огромного величественного дракона. Он озаглавлен: \"Daelas: Heir of Arodaleas\".",
                ]));
    SetInventory(([
                "/domains/town/obj/btable" : 1,
                "/domains/town/obj/bbucket" :1,
                "/domains/town/npc/lars" : ({ 60, 1})
                ]) );
    SetExits( ([
                "west" : "/domains/town/room/road",
                "out" : "/domains/town/room/road",
                ]) );
}
void init(){
    ::init();
}
