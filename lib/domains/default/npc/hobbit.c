#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("хоббит");
    SetAdjectives( ({"краснощекая", "пухленькая", "привлекательная"}) );
    SetId( ({"хоббит", "девушка"}) );
    SetShort("хоббит");
    SetLong("Краснощекая и пухленькая, эта девушка-хоббит довольно привлекательна. Вместе с тем она достаточно проворна, чтобы не дать себя в обиду.");
    SetLevel(1);
    SetMelee(1);
    SetRace("hobbit");
    SetGender("female");
}
void init(){
    ::init();
}
