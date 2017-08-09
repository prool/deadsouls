#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("серебряное кольцо");
    SetId(({"кольцо","серебряное кольцо"}));
    SetAdjectives( ({"красивое"}) );
    SetShort("красивое серебряное кольцо");
    SetLong("Это простое, но красивое кольцо сделано из  "+
            "обычного серебра. Внутри кольца вы замечаете надпись.");
    SetMass(1);
    SetBaseCost("silver",5000);
    SetArmorType(A_RING);
    SetItems(([
                ({"надпись","слова","гравировка","writing"}) : "Слова выгравированы в "+
                "таинственную надпись."
                ]) );
    SetRead(({"надпись","слова","гравировка","writing"}), "\"etaoin shrdlu\""  );

}

void init(){
    ::init();
}
