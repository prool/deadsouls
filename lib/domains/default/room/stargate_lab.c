#include <lib.h>
#include <daemons.h>

inherit LIB_ROOM;

int SignRead(){
    string list;
    list = implode(keys(STARGATE_D->GetStargates()),", ");
    write("Инструкция по использованию Звездных врат.");
    write("Система звездных врат этого мада позволяет телепортировать в пределах "
            "своей сети. Для того чтобы воспользоваться сетью, нужно найти "
            "не занятые Звездные врата, затем набрать имя любых друг врат. "
            "Затем пользователь входит в врата и, если все идет хорошо, телепортируется "
            "в названные Звездные врата. Чтобы переместиться, например, в Uruk "
            "вы должны набрать: dial uruk\n"
            "Когда Звездные врата активируются: enter stargate");
    write("На данный момент доступны следующие Звездные врата:");
    write("%^BOLD%^%^YELLOW%^"+list+"%^RESET%^");
    return 1;
}

static void create() {
    object ob;
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Обсерватория");
    SetLong("Это тестовая лаборатория для системы Звездных врат этого мада.\n"
            "%^BOLD%^%^GREEN%^Табличка с инструкциями висит здесь.%^RESET%^");
    SetItems(([
                ({ "табличка", "табличка с инструкциями", "инструкции", "инструкцию" }) : "На табличке написано, что это инструкции по использованию Звездных врат.",
                ]));
    SetExits( ([
                "north" : "/domains/default/room/wiz_corr_east2.c",
                ]) );
    SetInventory(([
                "/domains/default/obj/stargate" : 1,
                ]));
    SetRead("sign", (: SignRead() :) );
    SetProperty("no attack", 1);

}
int CanReceive(object ob) {
    return room::CanReceive();
}

void init(){
    ::init();
}
