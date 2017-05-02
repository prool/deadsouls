#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("кобольд");
    SetAdjectives( ({"вредный", "маленький"}) );
    SetId( ({"человекоящер", "ящер", "создание"}) );
    SetShort("маленький человекоящер");
    SetLong("Кобольды - это маленькие человекоящеры, отличающиеся крайне вредным характером. Из-за их злых шуток погиб не один шахтер.");
    SetLevel(1);
    SetMelee(1);
    SetRace("kobold");
    SetGender("male");
}
void init(){
    ::init();
}
