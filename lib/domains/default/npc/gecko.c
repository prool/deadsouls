#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("гекон");
    SetAdjectives( ({"зеленая", "маленькая"}) );
    SetId( ({"ящерица","гекон"}) );
    SetShort("гекон");
    SetLong("Это маленькая безобидная ящерица с зеленой кожей и большими глазами.");
    SetWimpy(80);
    SetLevel(1);
    SetMelee(1);
    SetRace("lizard");
    SetMaxHealthPoints(10);
    SetGender("male");
}
void init(){
    ::init();
}
