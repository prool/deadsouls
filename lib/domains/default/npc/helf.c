#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("оптис");
    SetId( ({"полуэльф"}) );
    SetAdjectives(({"non-player", "non player"}));
    SetShort("полуэльф Оптис");
    SetLong("Как и большинство представителей своего вида, Оптис очень привлекателен. Хотя его уши не такие заостренные, вид у него достаточно экзотичен, чтобы пользоваться популярностью у дам.");
    SetLevel(1);
    SetMelee(1);
    SetRace("half-elf");
    SetGender("male");
}
void init(){
    ::init();
}
