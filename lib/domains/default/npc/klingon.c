#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("клингон");
    SetAdjectives( ({"клингон", "молодой", "непредсказуемый"}) );
    SetId( ({"воин", "боец", "подросток"}) );
    SetShort("молодой клингон");
    SetLong("Молодые клингоны обязаны доказать свои бойцовские способности, поэтому часто они более непредсказумы в своей агрессии по сравнению со взрослыми представителями своей расы.");
    SetClass("fighter");
    SetLevel(5);
    SetMelee(1);
    SetRace("klingon");
    SetGender("male");
}
void init(){
    ::init();
}
