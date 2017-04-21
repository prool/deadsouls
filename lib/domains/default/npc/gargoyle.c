#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("гаргулья");
    SetAdjectives( ({"каменный", "гротескная", "уродливая", "отталкивающая"}) );
    SetId(({"нпс","моб","существо","монстр"}));
    SetShort("гротескная гаргулья");
    SetLong("Этот оживший каменный дух был создан для того, чтобы отпугивать всех и каждого. И это у него с успехом получается. Огромные красные глаза и свисающий язык заставят впасть в панику кого угодно.");
    SetLevel(1);
    SetMelee(1);
    SetRace("gargoyle");
    SetGender("male");
}
void init(){
    ::init();
}
