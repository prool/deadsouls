#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("великан");
    SetAdjectives( ({"забавный", "зеленый"}) );
    SetId(({"нпс","моб","существо","монстр"}));
    SetShort("зеленый великан");
    SetLong("Вы видите массивное существо, которое не кажется враждебным. Наоборот, он даже немного забавен. Кожа его зеленая, а одежда сделана из пальмовых листьев.");
    SetLevel(1);
    SetMelee(1);
    SetRace("giant");
    SetGender("male");
}
void init(){
    ::init();
}
