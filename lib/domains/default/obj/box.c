#include <lib.h>

inherit LIB_STORAGE;

void create() {
    ::create();
    SetKeyName("ящик");
    SetId( ({ "ящик" }) );
    SetAdjectives( ({ "маленький", "пластиковый" }) );
    SetShort("маленький пластиковый ящик");
    SetLong("Это маленький пластиковый ящик для хранения вещей.");
    SetMass(274);
    SetMaxCarry(500);
}
