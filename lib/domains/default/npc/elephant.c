#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("слон");
    SetAdjectives( ({"docile", "pink", "friendly", "large", "very large"}) );
    SetId(({"нпс","моб","существо","животное"}));
    SetShort("розовый слон");
    SetLong("Это очень крупное животное, но оно кажется смирным и даже дружелюбным. Остается только непонятным, розовый цвет его натуральный или его кто-то в него покрасил?");
    SetLevel(1);
    SetMelee(1);
    SetRace("elephant");
    SetGender("female");
}
void init(){
    ::init();
}
