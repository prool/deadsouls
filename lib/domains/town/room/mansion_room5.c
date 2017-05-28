#include <lib.h>
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Кабинет");
    SetLong("Вы зашли в кабинет хозяина особняка. "+
      "Здесь царит страшный беспорядок. Кажется, что "+
      "эту комнату разграбили в большой спешке. "+
      "Если тут и было что-нибудь ценное, то теперь "+
      "тут этого нет.");
    SetExits( ([
        "west" : "/domains/town/room/mansion_uhall3"
      ]) );

    SetDoor("west", "/domains/town/doors/m5.c");

}
void init(){
    ::init();
}
