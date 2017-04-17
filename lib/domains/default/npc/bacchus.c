#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("Бахус");
    SetAdjectives( ({"римский", "пьяный"}) );
    SetId( ({"бог", "бог вина", "дионис", "дионисий"}) );
    SetShort("Бахус, римский бог вина");
    SetLong("Что здесь делает римский бог вина остается для всех загадкой, даже для него самого. На данный момент все, что ему нужно, это выспаться после последней попойки.");
    SetLevel(200);
    SetMelee(1);
    SetRace("god");
    SetGender("male");
    SetSleeping(500);
}
void init(){
    ::init();
}
