#include <lib.h>
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Лечебница");
    SetLong("Это рабочее помещение лекаря Клепиуса. "
            "Здесь он оказывает медицинские услуги "
            "клиентам. В углу вы замечаете полный книг и "
            "свитков шкаф. Приемная лечебницы на "
            "востоке.");
    SetItems( ([
                "шкаф" : "Здесь Clepius хранит "
                "медицинские руководства и справочники.",
                ({"свитки","книги","книг и свитков"}) : "Это "
                "содержимое шкафа лекаря Клепиуса.",
                "угол" : "Здесь находится шкаф."
                ]) );
    SetExits( ([ 
                "east" : "/domains/town/room/healer",
                ]) );
    SetRead( ({"свитки","книги","книг и свитков"}) , "Они принадлежат Клепиусу и он не разрешает читать их кому попало." ); 
    SetProperty("no attack", 1);
    SetInventory(([
                "/domains/town/obj/bbucket" :1,
                "/domains/town/npc/clepius" : ({60, 1})
                ]) );
    SetProperty("busy",0);

}
int CanReceive(object ob) {
    if(playerp(ob) && !creatorp(ob) && GetProperty("busy") == 1){
        message("info","Лекарь сейчас занят другим пациентом. Пожалуйста, "+
                "подождите пока он с ним закончит.",ob);
        return 0;
    }
    return 1;
}
void init(){
    ::init();
}
