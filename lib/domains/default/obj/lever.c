#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

void create(){
    ::create();
    SetKeyName("чека от гранаты");
    SetId(({"чека","рычажок"}));
    SetAdjectives(({"гранаты","ручной гранаты","маленькая","металлическая"}));
    SetShort("маленькая металлическая чека");
    SetLong("Это чека от ручной гранаты.");
    SetMass(1);
    SetDollarCost(0);
    SetVendorType(VT_TREASURE);
}
void init(){
    ::init();
}
