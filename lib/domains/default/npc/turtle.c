#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("ложная черепаха");
    SetAdjectives( ({"ложная", "странная"}) );
    SetId( ({"черепаха", "тортилла"}) );
    SetShort("ложная черепаха");
    SetLong("у этого странного существа тело черепахи, но голова теленка.");
    SetLevel(1);
    SetMelee(1);
    SetRace("tortoise");
    SetGender("male");
}
void init(){
    ::init();
}
