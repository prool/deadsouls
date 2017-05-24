#include <lib.h>
inherit LIB_SHOP;

int read_sign();
static void create() {
    ::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Магическая лавка");
    SetLong("Вы находитесь в магической лавке, в которой можно продать или купить волшебные безделушки. Наверху находится кладовая, а вход в гильдию магов находится на юге.");
    SetItems(([
                ({"лавка","магазин","место"}) : "Это местный магический магазин.",
                ({ "табличка" ,"табличка на стене" }): "Вы видите на стене табличку, которую можно прочесть.",
                ]));
    SetExits( ([
                "south" : "/domains/town/room/magic_guild",
                "east" : "/domains/town/room/south_road1",
                "up" : "/domains/town/room/magic_shop2.c",
                ]) );
    SetRead("табличка", (: read_sign :) );
    SetInventory( ([
                "/domains/town/npc/oana" : ({60, 1}),
                "/domains/town/obj/bbucket" : 1,
                ]) );
}
int read_sign(){
    write("Памятка по ведению дел\n");
    write("list : перечисляет все вещи, которые Оана может продать");
    write("appraise <item> : спросить Оану, сколько она предложит за эту вещь");
    write("price <item> : спросить Оану, сколько она запросит за эту вещь");
    write("show <item> : попросить Оану показать поближе эту вещь\n");
    write("\nbuy <item> from oana\nsell <item> to oana\n");
    write("Цены указаны в серебряных монетах.");
    write("\n\nМы все еще официально не открылись, ");
    write("поэтому у нас не так много товаров. Но, если вы хотите, ");
    write("на юге в гильдии магов вам предложат что-нибудь еще!");

    return 1;
}
void init(){
    ::init();
}
