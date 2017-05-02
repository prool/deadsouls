#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("клэр");
    SetId( ({"нимфа", "дэйнс", "клэр дэйнс", "девушка"}) );
    SetAdjectives(({"non-player", "non player"}));
    SetShort("Клэр Дэйнс");
    SetLong("Эта нимфа кажется совершенно потерянной, возможно она из свиты лесной богини и теперь ищет ее.");
    SetLevel(1);
    SetMelee(1);
    SetRace("nymph");
    SetGender("female");
}
void init(){
    ::init();
}
