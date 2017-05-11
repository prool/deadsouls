#include <lib.h>

inherit LIB_STORAGE;

void create() {
    ::create();
    SetKeyName("сундук");
    SetId(({"сундук","деревянный сундук"}));
    SetShort("деревянный сундук");
    SetLong("Это крепкий деревянный сундук, используемый для хранения ценных предметов.");
    SetInventory(([
                "/domains/default/obj/meter" : 1,
                "/secure/obj/staff" : 1,
                "/domains/default/obj/gps" : 1,
                "/domains/town/armor/collar" : 1,
                "/secure/obj/medtric" : 1,
                "/domains/default/armor/wizard_hat" : 1,
                "/domains/default/armor/robe" : 1,
                "/domains/default/armor/badge" : 1,
                "/domains/default/obj/pinger" : 1,
                "/domains/default/armor/jade_ring" : 1,
                "/domains/default/armor/breather" : 1,
                "/domains/default/obj/manual" : 1,
                "/secure/obj/memo" : 1,
                "/secure/obj/machine" : 1,
                "/secure/obj/control" : 1,
                ]));
    SetMass(2000);
    SetBaseCost(50);
    SetMaxCarry(10000);
    SetPreventPut("Вы не можете положить это сюда!");
    SetCanClose(1);
    SetClosed(1);
}
mixed CanGet(object ob) { return "Крышка не открывается.";}
void init(){
    ::init();
}
