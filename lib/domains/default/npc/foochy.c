#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("фучи");
    SetAdjectives( ({"нелепая", "маленькая", "розовый"}) );
    SetId(({"нпс","моб","собачка","животное","пудель"}));
    SetShort("розовый пудель Фучи");
    SetLong("Довольно нелепая маленькая собачка, похожая на плюшевую игрушку.");
    SetLevel(1);
    SetMelee(1);
    SetRace("dog");
    SetGender("female");
}
void init(){
    ::init();
}
