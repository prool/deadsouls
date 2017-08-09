#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("камуфляжный шлем");
    SetId(({"шлем","cover","kevlar"}));
    SetAdjectives(({"камуфляжный","боевой","прочный"}));
    SetShort("камуфляжный шлем");
    SetLong("Этот металлический шлем покрыт дополнительно специальным "+
            "покрытием, смягчающим удары по голове. Кроме того, "+
            "он выкрашен в неприметный серо-зеленый цвет.");
    SetMass(50);
    SetBaseCost("silver",500);
    SetArmorType(A_HELMET);
    SetProtection(BLUNT, 25);
    SetProtection(BLADE, 25);
    SetProtection(KNIFE, 25);
    SetProtection(PIERCE, 25);
}

void init(){
    ::init();
}
