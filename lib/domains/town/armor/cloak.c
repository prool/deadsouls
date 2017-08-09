/* This is kind of broken, sorry. Will maybe fix someday. */

#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("зеленая накидка");
    SetId(({"накидка"}));
    SetAdjectives(({"зеленая","эльфийская"}));
    SetShort("зеленая накидка");
    SetLong("Вы видите зеленую накидку эльфийской работы с капюшоном. "
            "Вы можете попробовать \"wear hood on cloak\".");
    SetMass(200);
    SetBaseCost("silver",500);
    SetDamagePoints(100);
    SetProtection(BLADE,10);
    SetProtection(KNIFE,10);
    SetArmorType(A_CLOAK);
    //AddItem(new("/domains/town/obj/cloak_hood"));
}

void init(){
    ::init();
}

//The following are necessary in order to be
//able to see and manipulate the dummy object
mixed inventory_visible(){ return 1; }
mixed inventory_accessible(){ return 1; }
