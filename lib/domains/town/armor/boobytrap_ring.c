/*
 * Note that this ring, unlike the boobytrapped dagger, does
 * not check to see if it has been previously armed. This prevents
 * a player from disarming the ring by simply logging out
 * and logging back in.
 */

#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
#include <boobytraps.h>

inherit LIB_ARMOR;

void boobytrap_me(){
    object shadowtrap;
    if(!clonep(this_object())) return; /* Avoids boobytrapping the blueprint ob */

    shadowtrap = new("/shadows/needle_trap");
    shadowtrap->SetTrapDescription("Отравленная игла.");
    shadowtrap->SetTrapLevel(50);
    shadowtrap->SetAutoResets(0);
    shadowtrap->SetTrapType(BOOBYTRAP_WEAR);
    shadowtrap->eventShadow(this_object());
}

static void create(){
    armor::create();
    SetKeyName("серебряное_кольцо");
    SetId(({"кольцо","серебряное кольцо"}));
    SetAdjectives( ({"великолепное"}) );
    SetShort("великолепное серебряное кольцо");
    SetLong("Это самое обычное кольцо из серебра, "+
            "которые обычно носят на пальце. Изнутри на кольцо выгравирована надпись.");
    SetMass(1);
    SetBaseCost("silver",1000);
    SetArmorType(A_RING);
    SetItems(([
                ({"гравировка","слова","надпись","writing"}) : "Слова выгравированы в "+
                "таинственную надпись."
                ]) );
    SetRead(({"гравировка","слова","надпись","writing"}), "\"etaoin shrdlu\""  );
    boobytrap_me();
}

void init(){
    ::init();
}
