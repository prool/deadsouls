#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("вепрь");
    SetAdjectives( ({"огромный", "дикий", "волосатый", "смертоносный"}) );
    SetId( ({"вепрь", "животное"}) );
    SetShort("дикий вепрь");
    SetLong("Этот огромный волосатый вепрь полон агрессии. Хоть он и родственник обычной свиньи, он так же смертоносен, как и тигр, лев или медведь благодаря своим огромным бивням.");
    SetLevel(1);
    SetMelee(1);
    SetRace("pig");
    SetGender("male");
}
void init(){
    ::init();
}
