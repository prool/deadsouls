#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;
inherit LIB_BANE;

static void create(){
    armor::create();
    SetKeyName("ошейник");
    SetId(({"repellent_collar","ошейник"}));
    SetAdjectives( ({"repellent","odd","plastic","белый"}) );
    SetShort("белый ошейник");
    SetLong("Вы видите похожий на собачий ошейник, сделанный из  "+
            "странного белого материала. На ошейнике "+
            "что-то написано.");
    SetProperties(([
                "no steal" : 1,
                ]));
    SetRead("Ошейник защищающий от болезней и паразитов. Только для билдеров!.");
    SetMass(10);
    SetArmorType(A_COLLAR);
    SetBane(({"all"}));
}

void init(){
    ::init();
}
