#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("полурослик");
    SetId(({"нпс","моб","существо","полурослик"}));
    SetAdjectives(({"non-player", "non player"}));
    SetShort("полурослик");
    SetLong("Полурослики выглядят точно также, как и их более именитые родственники - хоббиты. Только они еще более скрытные и скромные, поэтому истории о них часто умалчивают.");
    SetLevel(1);
    SetMelee(1);
    SetRace("halfling");
    SetGender("male");
}
void init(){
    ::init();
}
