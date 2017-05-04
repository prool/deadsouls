#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("дракон");
    SetAdjectives( ({"огромная", "красный", "опасный"}) );
    SetId(({"нпс","моб","дракон","монстр"}));
    SetShort("красный дракон");
    SetLong("Красный дракон - одно из самых жестоких и опасных существ этого мира. Эта огромная тварь раздавит вас и даже не заметит этого.");
    SetClass("fighter");
    SetLevel(15);
    SetMelee(1);
    SetRace("dragon");
    SetGender("male");
}
void init(){
    ::init();
}
