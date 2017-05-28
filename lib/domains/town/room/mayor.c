#include <lib.h>
inherit LIB_ROOM;

static void create() {
    room::create();
    SetTown("town");
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Офис мэра");
    SetLong("Вы зашли в довольно тесный офис мэра города. Здесь царит страшный беспорядок, характеризиующий, видимо, стиль работы и привычки мэра.");
    SetProperties (([
                "no attack":1, 
                "no bump":1, 
                "no steal":0, 
                "no magic":0, 
                "no paralyze":0, 
                "no teleport":0]));
    SetItems(([  
                "беспорядок" : "Здесь повсюду разбросаны бумаги и папки, хотя во всем этом прослеживается некая закономерность." ,
                ({"бумага","бумаги","папка","папки"}) : "Они свидетельствуют о сильной занятости мэра и его неординарного ума."]));
    SetExits( ([ 
                "down" : "/domains/town/room/thall",
                ]) );
    SetInventory(([  "/domains/town/npc/mayor" : ({60, 1})]));
}
void init() {
    ::init();
    SetSmell(([]));
    SetListen(([]));
}
