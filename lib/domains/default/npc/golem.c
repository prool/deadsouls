#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("голем");
    SetAdjectives( ({"массивный", "глиняный", "высокий"}) );
    SetId( ({"глиняный голем", "голем", "эмет"}) );
    SetShort("Эмет-голем");
    SetLong("Эмет - массивный глиняный голем с толстыми руками и ногами. На его лбу нацарапаны загадочные символы.");
    SetLevel(10);
    SetMelee(1);
    SetRace("golem");
    SetGender("neuter");
}
void init(){
    ::init();
}
