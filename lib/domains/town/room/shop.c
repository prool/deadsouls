#include <lib.h>
inherit LIB_SHOP;

int read_sign();
static void create() {
    ::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Бакалея");
    SetLong("Вы зашли в местный бакалейный магазин, где можете продать или купить товары первой необходимости. Висящая на стене табличка объясняет как это сделать. Наберите 'читать табличку'. К югу отсюда находится Восточная деревенская дорога. Внизу под прилавком вы замечаете лестницу в кладовую.");
    SetItems(([
        ({"бакалея","магазин","место"}) : "Вы находитесь в местном магазине.",
        ({ "табличка" ,"табличка на стене" }): "Вы видите на стене табличку, которую можно прочесть.",
      ]));
    SetExits( ([
        "south" : "/domains/town/room/vill_road2",
        "down" : "/domains/town/room/shop2.c",
      ]) );
    SetInventory(([
        "/domains/town/obj/bbucket" : 1,
        "/domains/town/npc/otik" : ({60, 1}),
      ]));
    SetRead("табличку", (: read_sign :) );

    SetDoor("down", "/domains/town/doors/otik_d.c");

}
int read_sign(){
    write("ИНСТРУКЦИЯ\n");
    write("список : выводит список вещей на продажу");
    write("оценить <item> : выводит цену, которую Отик предложит за ваш предмет");
    write("цена <item> : выводит цену предмета из магазина");
    write("показать <item> : более подробная информация о предмете\n");
    write("\nкупить <item> у отика\nпродать <item> отику\n");
    write("Только наличные!");
    return 1;
}
void init(){
    ::init();
}
