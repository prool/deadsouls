#include <lib.h>
#include ROOMS_H

inherit LIB_ROOM;

int initialized = 0;

void create() {
    room::create();
    SetAmbientLight(5);
    SetShort("Темная пещера");
    SetLong("Это небольшая пещера у подножия скал. В северной стене установлена каменная дверь. На одной из стен что-то написано.");
    SetExits( ([
        "out" : "/domains/town/virtual/forest/-4,25",
        "south" : "/domains/town/virtual/forest/-4,25",
        "north" : "/domains/town/room/cave1.c",
      ]) );
    SetItems(([
        ({ "послание", "что-то написано","каракули" }) : "Грубые каракули, которые можно прочесть.", 
        ({ "стена" }) : "Это каменная поверхность пещеры.",
    ]) );
    SetRead(({ "послание", "каракули" })  
        , "Друг, набери номер лаборатории." );
    SetDoor("north", "/domains/town/doors/stone.c");
}

void init(){
    ::init();
    if(!initialized){
        object door = present("каменная дверь",this_object());
        if(!door) return;
        door->SetItems( ([
            ({"надпись"}) : "Вы видите слова на эльфийском.",
          ]) );
        SetInventory(([
            "/domains/town/obj/stargate3" : 1,
          ]));
        SetClimate("indoors");
        door->SetRead( ([
            ({"надпись"}) : "Скажи пароль, друг, и войди.",
            "default" : "Попробуйте: read надпись on дверь"
          ]) );
        door->SetLanguage("Edhellen");
        initialized = 1;
    }
}

varargs mixed eventHearTalk(object who, object target, int cls, string verb,
  string msg, string lang) {
    int decoded = 0;
    object door = present("каменная дверь",this_object());
    if(door) door = door->GetDoor();
    if(door && door->GetClosed() && lower_case(lang) == "edhellen"
      && who->GetLanguageLevel(lang) > 50 && 
      grepp(lower_case(msg),"друг"))
        decoded = 1;
    room::eventHearTalk(who,target,cls,verb,msg,lang);
    if(decoded){
        eventPrint("С громким скрипом дверь открылась!");
        door->SetClosed(0);
    }
    return 1;
}
