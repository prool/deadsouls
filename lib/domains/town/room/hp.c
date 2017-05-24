#include <lib.h>

inherit LIB_ROOM;

varargs string readMenu() {
    string ret = "\tБутылка пива\t\t\t1 gold\n"+
    "\tБутылка вина\t\t\t\t2 gold\n"+
    "\tБутылка виски\t\t\t3 gold\n";
    return ret;
}

void create(){
    ::create();
    SetAmbientLight(30);
    SetShort("Паб Гарри");
    SetLong("Паб Гарри - это обычный портовый бар, в котором собираются моряки чтобы выпить и порассказывать байки. На одной из стен висит меню, в котором перечислены доступные напитки. На западе вы замечаете заднюю комнату.");
    SetClimate("indoors");
    SetItems( ([
        ({"стена", "стены"}) : "Если бы они могли говорить, то рассказали бы немало удивительного.",
        "меню" : "Вы можете прочесть меню. На нем есть логотип в виде "+
        "волчьей головы на палке.",
        ({"комната","задняя комната"}) : "Возможно, там кладовая.",
        "гарри" : "Гарри никто не видел уже довольно давно.",
      ]) );
    SetSkyDomain("town");
    SetRead("menu", (: readMenu :) );
    SetInventory(([
        "/domains/town/npc/brandy" : 1,
      ]) );
    SetExits( ([
        "east" : "/domains/town/room/bwalk1.c",
      ]) );
}

void init(){
    ::init();
}
