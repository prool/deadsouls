#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;
static void create(){
    armor::create();
    SetKeyName("боевая униформа");
    SetId(({"униформа","боевая","bdu's","fatigues"}));
    SetAdjectives(({"камуфляжная","battle","dress","combat"}));
    SetShort("боевая униформа");
    SetLong("Эта униформа состоит из камуфляжной футболки и "+
            "штанов. Она зеленого цвета с черными и коричневыми пятнами, "+
            "одевший ее будет практически незаметен в лесу.");
    SetMass(10);
    SetBaseCost("silver",100);
    SetDamagePoints(100);
    SetArmorType(A_BODY_ARMOR);
}

void init(){
    ::init();
}
