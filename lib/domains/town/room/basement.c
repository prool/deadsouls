#include <lib.h>
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Подвал церкви");
    SetLong("Это темный, затхлый подвал деревенской церкви. В западной стене вы видите дверь лифта.");
    SetItems(([
                ({"лифт","дверь лифта","дверь","стена","западная стена"}) : "В западной стене "+
                "установлен лифт. Рядом с ней вы видите "+
                "кнопку, вероятно для вызова кабины лифта.",
                ]) );
    SetInventory(([
                "/domains/town/obj/couch" : 1,
                "/domains/town/npc/leo" : ({60, 1})
                ]));
    SetExits( ([
                "west" : "/domains/town/room/elevator",
                ]) );
    //AddStuff( ({"/domains/town/npc/leo"}) );
}
void init(){
    ::init();
    if(!present("button",this_object())) AddItem(new("/domains/town/obj/basement_button"));
}
