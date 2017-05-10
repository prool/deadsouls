#include <lib.h>

inherit LIB_STORAGE;

void create() {
    ::create();
    SetKeyName("ящик боеприпасов");
    SetId(({"ящик"}));
    SetAdjectives(({"металлический","большой"}));
    SetShort("ящик с боеприпасами");
    SetLong("Этот большой металлический ящик содержит всевозможные виды "+
            "боеприпасов. ");
    SetMass(200);
    SetDollarCost(50);
    SetMaxCarry(500);
    SetCanClose(1);
    SetClosed(0);
    SetInventory( ([
                "/domains/default/obj/9mmclip": ({ 60, 2 }),
                "/domains/default/obj/223clip": ({ 60, 2 }),
                "/domains/default/weap/grenade": 3,
                ]) );
    SetPreventGet("The metal ammunition box does not budge.");
}

void init(){
    ::init();
}
