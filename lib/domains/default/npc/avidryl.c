#include <position.h>
#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("авидрил");
    SetId(({"нпс","моб","существо","птицечеловек"}));
    SetAdjectives(({"non-player", "non player"}));
    SetShort("авидрил");
    SetLong("Это легендарный авидрил или 'птицечеловек'. Он очень походил бы на человека, если бы не его огромный птичий хвост. Также у него есть пара великолепных крыльев, которые он использует для полета.");
    SetAutoStand(1);
    SetPosition(POSITION_FLYING);
    SetClass("explorer");
    SetLevel(5);
    SetRace("avidryl");
    SetGender("male");
}
void init(){
    ::init();
}
