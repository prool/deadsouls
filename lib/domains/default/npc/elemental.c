#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("элементаль");
    SetId( ({"элементаль", "manifestation"}) );
    SetAdjectives( ({"эфирный"}) );
    SetShort("эфирный элементаль");
    SetLong("Обычно призванные элементали принадлежат одной из четырех стихий: земли, воды, воздуха или огня. Но, этот не похож ни на что, вероятно он создан из самого эфира.");
    SetLevel(1);
    SetMelee(1);
    SetRace("elemental");
    SetGender("neuter");
}
void init(){
    ::init();
}
