#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;
inherit LIB_BANE;

static void create(){
    armor::create();
    SetKeyName("ошейник");
    SetId(({"ошейник"}));
    SetAdjectives( ({"repellent","odd","plastic","white"}) );
    SetShort("кожаный ошейник");
    SetLong("Этот ошейник сделан из мягкой белой кожи, "+
            "с внешней стороны его что-то написано. ");
    SetProperties(([
                "no steal" : 1,
                ]));
    SetRead("Противопаразитный ошейник, защищает от болезней. Только для тестовых персонажей!");
    SetMass(10);
    SetBaseCost("silver", 10);
    SetDamagePoints(100);
    SetArmorType(A_COLLAR);
    SetBane(({"all"}));
}
void init(){
    ::init();
}
