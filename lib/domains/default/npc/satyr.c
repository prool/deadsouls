#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("сатир");
    SetAdjectives( ({"огромного", "волосатого", "огромный", "волосатый"}) );
    SetId( ({"мужчина", "монстр", "тварь"}) );
    SetShort("сатир");
    SetLong("Вы видите огромного волосатого мужчину с козлиными ногами. Сквозь гриву грязных волос растет пара острых рогов. Весь его вид указывает на то, что это не разумная личность, а дикая лесная тварь.");
    SetLevel(1);
    SetMelee(1);
    SetRace("satyr");
    SetGender("male");
}
void init(){
    ::init();
}
