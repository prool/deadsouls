#include <lib.h>
inherit LIB_ROOM;

int maxnoob = MAX_NEWBIE_LEVEL;

int PreExit(){
    object guard = present("gate guard",this_object());
    if(!MAX_NEWBIE_LEVEL) maxnoob = 3;
    if(((MAX_NEWBIE_LEVEL && !newbiep(this_player())) || 
        this_player()->GetLevel() > maxnoob) &&
      (!this_player()->GetInvis() && !creatorp(this_player()) &&
        !present("testchar badge",this_player()))){
        if(guard && living(guard)){
            present("gate guard",this_object())->eventForce("say Ты слишком большой, чтобы проскользнуть мимо меня. Ты больше не попадешь в особняк.");
            return 0;
        }
    }
    if((newbiep(this_player()) || this_player()->GetLevel() <= maxnoob)
      && guard && living(guard)){
        tell_object(this_player(),"Вы такой новичок, что охранник ворот даже не замечает, как вы проскользнули мимо него.");
        tell_room(this_object(),this_player()->GetName()+" проник мимо стража ворот.",({ this_player() }) );
    }
    return 1;
}	

static void create() {
    room::create();
    SetClimate("outdoors");
    SetAmbientLight(30);
    SetShort("Ворота особняка");
    SetLong("Вы остановились к северу от ворот огромного, "+
      "красивого особняка, который гордо возвышается на юге. "+
      "Изящные колонны крыльца особняка говорят о "+
      "богатстве и важности тех, кто живет "+
      "здесь. Густой плющ покрывает ворота и кирпичные стены, "+
      "окружающие имение.");
    SetItems( ([
        "ворота" : "Вы видите красивые ворота ручной работы.",
        ({"имение", "особняк"}) : "Земли этого имения на юге.",
        ({"колонна","колонны","изящные колонны"}) :
        "Колонны поддерживают переднюю часть фасада здания. "
        "Они покрыты резьбой в виде "
        "переплетенных листьев и лоз, что показывает "
        "их изысканность.",
        ({"плющ","густой плющ"}) : "Лозы плюща "
        "покрывают кирпичные стены и ворота толстым слоем, "
        "так что их сложно разглядеть под ним.",
        ({"стена","стены"}) : "Это архитектурное сооружение, которое"
        "препятствует проникновению внутрь нежеланных гостей. Они сделаны из кирпича и "
        "кажутся старыми, но прочными.",
      ]) );
    SetSkyDomain("town");
    SetExits( ([
        "north" : "/domains/town/room/road2.c",
      ]) );
    SetInventory(([
        "/domains/town/npc/mp" : ({ 3600, 1 }),
      ]));
    AddExit("south", "/domains/town/room/mansion_ext", (: PreExit :));
    AddItem(new("/domains/town/obj/lamp"));
    SetProperty("no attack", 1);
}
void init(){
    ::init();
}
