#include <lib.h>
inherit LIB_ROOM;

static void create() {
    room::create();
    SetTown("town");
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Школа");
    SetLong("Вы зашли небольшое однокомнатное здание, играющее важную роль в жизни небольшого города. Заинтересованные люди приходят сюда узнавать новое у странствующих учителей и ученых, когда те появляются в городе.");
    SetProperties (([
                "no attack":1, 
                "no bump":1, 
                "no steal":0, 
                "no magic":0, 
                "no paralyze":0, 
                "no teleport":0]));
    SetItems(([]));
    SetInventory(([
                "/domains/town/npc/bugg" : ({60, 1}),
                ]));
    SetExits(([
                "south" : "/domains/town/room/vill_road4",
                ]));

}
void init() {
    ::init();
    SetSmell(([]));
    SetListen(([]));
}
