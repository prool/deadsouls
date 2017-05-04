#include <lib.h>
#include <size_types.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("паук");
    SetAdjectives( ({"огромный", "волосатый"}) );
    SetId(({"нпс","моб","насекомое","паук"}));
    SetShort("огромный паук");
    SetLong("Этот огромный волосатый паук размером с кошку. С его отвратительной пасти капает какая-то вязкая жидкость.");
    SetWimpy(80);
    SetMelee(1);
    SetLevel(1);
    SetRace("arachnid");
    SetClass("explorer");
    SetGender("male");
}
void init(){
    ::init();
}
