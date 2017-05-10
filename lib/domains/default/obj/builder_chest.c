#include <lib.h>

inherit LIB_STORAGE;

void create() {
    ::create();
    SetKeyName("сундук");
    SetId(({"сундук","деревянный сундук"}));
    SetShort("деревянный сундук");
    SetLong("Это крепкий деревянный сундук, используемый для хранения ценных предметов.");
    SetInventory(([
                "/domains/town/armor/collar" : 1,
                "/domains/default/obj/bguide" : 1,
                "/secure/obj/machine" : 1,
                "/domains/default/obj/meter" : 1,
                "/secure/obj/control" : 1,
                "/secure/obj/memo" : 1,
                "/secure/obj/staff" : 1,
                "/domains/default/obj/pinger" : 1,
                "/secure/obj/medtric" : 1,
                ]));
    SetMass(2000);
    SetBaseCost(50);
    SetMaxCarry(10000);
    SetPreventPut("Вы не можете положить это сюда!");
    SetPreventGet("Крышка не открывается.");
    SetCanClose(1);
    SetClosed(1);
}

void init(){
    ::init();
}
