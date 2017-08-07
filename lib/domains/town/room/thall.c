#include <lib.h>
inherit LIB_ROOM;

static void create() {
    room::create();
    SetTown("town");
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Ратуша");
    SetLong("Вы зашли в небольшое скромное помещение - ратушу этого города. Офисы клерка и нотариуса находятся на севере, а комната мэра - наверху. На юге вы видите широкую дорогу, а на северо-востоке - регистратора избирателей.");
    SetProperties (([
                "no attack":1, 
                "no bump":1, 
                "no steal":0, 
                "no magic":0, 
                "no paralyze":0, 
                "no teleport":0]));
    SetItems(([]));
    SetExits( ([
                "south" : "/domains/town/room/vill_road3",
                "northeast" : "/domains/town/room/voters",
                "up" : "/domains/town/room/mayor",
                "north" : "/domains/town/room/clerk.c",
                ]) );
    SetInventory(([]));

}
void init() {
    ::init();
    SetSmell(([]));
    SetListen(([]));
}
