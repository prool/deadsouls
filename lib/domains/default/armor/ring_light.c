#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("кольцо");
    SetId(({"кольцо"}));
    SetAdjectives( ({"магическое","светящееся","бриллиантовое"}) );
    SetShort("бриллиантовое светящееся кольцо");
    SetLong("Это магическое кольцо испускает очень яркий свет, "+
            "который может осветить комнату.");
    SetRadiantLight(30);
    SetMass(1);
    SetBaseCost("silver",5000);
    SetArmorType(A_RING);
}

void init(){
    ::init();
}
