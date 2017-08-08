#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("кожаный ботинок");
    SetId(({"ботинок","левый ботинок"}));
    SetAdjectives(({"военный","левый","черный","кожаный","боевой"}));
    SetShort("черный кожаный ботинок");
    SetLong("Вы видите ботинок в военном стиле, сделанный из черной кожи. Его "+
            "можно одеть на левую ногу.");
    SetMass(20);
    SetBaseCost("silver",25);
    SetProtection(BLUNT,5);
    SetProtection(BLADE,5);
    SetProtection(KNIFE,5);
    SetArmorType(A_BOOT);
    SetRestrictLimbs(({"left foot"}));
}

void init(){
    ::init();
}
