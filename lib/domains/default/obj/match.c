#include <lib.h>

inherit LIB_MATCH;

static void create() {
    match::create();
    SetKeyName("спичка");
    SetId("спичка");
    SetAdjectives( ({ "деревянная" }) );
    SetShort("деревянная спичка");
    SetLong("Деревянная спичка, которая может загореться, если вы по ней ударите.");
    SetRadiantLight(2);
    SetStrikeChance(50);
    SetMinHeat(10);
    SetFuelRequired(1);
    SetMaxFuel(10);
    SetFuelAmount(10);
    SetRefuelable(0);
    SetMass(5);
    SetBurntValue(1);
}
