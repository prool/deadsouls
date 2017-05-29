#include <lib.h>
inherit LIB_ROOM;

int open;
static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Спальня владельца особняка");
    SetLong("Вы зашли в спальню владельца особняка. "
      "Декор здесь красивый, богато украшенный и экстравагантный. "
      "Очевидно, что живущие здесь люди очень богаты и обладают отличным "
      "вкусом. ");
    SetItems( ([
        "декор" : "Впечатляющий, богато украшенный и изысканный.",
      ]) );
    SetInventory( ([
        "/domains/town/obj/bed" : 1,
        "/domains/town/obj/wardrobe" : 1,
      ]) );
    SetExits( ([
        "north" : "/domains/town/room/mansion_uhall3"
      ]) );
    open = 0;

    SetDoor("north", "/domains/town/doors/m7.c");

}
int OpenPassage(){
    string desc;
    if(open == 1) return 1;
    tell_room(environment(this_player()),"Открылся секретный проход!");
    open = 1;
    desc = GetLong();
    desc += "\n%^MAGENTA%^Здесь находится недавно открытый секретный проход. %^RESET%^";
    SetLong(desc);
    AddItem(({"секретный проход","проход"}) , "Этот проход куда-то ведет.");
    SetEnters(([ 
        "passageway" : "/domains/town/room/mansion_room11",
        "secret passageway" : "/domains/town/room/mansion_room11"
      ]) );
    return 1;
}
void init(){
    ::init();
}
