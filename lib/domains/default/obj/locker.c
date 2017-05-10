#include <lib.h>

inherit LIB_STORAGE;

void create() {
    ::create();
    SetKeyName("шкафчик");
    SetId(({"шкаф","object"}));
    SetAdjectives(({"металлический","высокий","большой"}));
    SetShort("высокий металлический шкафчик");
    SetLong("Этот высокий шкаф сделан для того, "+
            "чтобы держать в нем доспехи.");
    SetInventory(([
                "/domains/default/armor/pcannon" : 1,
                "/domains/default/armor/scoutsuit" : 1,
                "/domains/default/armor/chainmail" : 5,
                ]));
    SetMass(2000);
    SetBaseCost("silver",150);
    SetMaxCarry(10000);
    SetCanClose(1);
    SetClosed(0);
    SetPreventGet("Шкафчик не открывается.");
}
void init(){
    ::init();
}
