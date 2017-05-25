#include <lib.h>
inherit LIB_ROOM;

int found;
string SearchFun(){
    string result;
    if(found == 0){
        result="Вы обыскали комнату и нашли золотое кольцо!";
        tell_room(this_object(),this_player()->GetName()+ 
          " обыскал комнату и нашел что-то. ",
          ({ this_player() }) );
        if(!new("/domains/town/armor/newbie_ring")->eventMove(this_player()))
            new("/domains/town/armor/newbie_ring")->eventMove(this_object());
        found = 1;
        return result;
    }
    return "Вы не нашли ничего необычного.";
}
static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Гостевая комната, западная часть");
    SetLong("Вы находитесь в западной части гостевой комнаты особняка. "
      "Эта комната роскошно обставлена и меблирована. "
      "Хотя похоже, что здесь уже очень давно никто "
      "не прибирался. ");
    SetExits( ([
        "east" : "/domains/town/room/mansion_uhall1"
      ]) );
    SetItems( ([ 
        ({"тут","место","помещение","комната"}) : "Вы в гостевой комнате особняка.",
        "пыль" : "Все здесь покрыто пылью, что несколько неожидано для такого красивого места.",
      ]) );
    SetInventory(([
        "/domains/town/obj/gbed" : 1,
      ]) );
    SetSearch( ([ "default"  : (: SearchFun :)  ]) );
    found = 0;

    SetDoor("east", "/domains/town/doors/m2.c");

}
void init(){
    ::init();
    AddSearch( ({"тут","место","помещение","комната"})  , (: SearchFun :)  );
}
