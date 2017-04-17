#include <lib.h>
#include <position.h>

inherit LIB_CHAMBER;

static void create() {
    chamber::create();
    SetKeyName("гроб");
    SetId(({"гроб"}));
    SetAdjectives(({"сосновый", "простой"}));
    SetShort("гроб");
    SetLong("Это простой сосновый ящик для хранения останков "+
            "умершего.");
    SetRace("vehicle");
    SetPosition(POSITION_NULL);
    SetMelee(0);
    SetNoClean(1);
    SetMount(1);
    SetMountStyle("driven");
    SetVisibleRiders(0);
    SetOpacity(100);
    SetMaxHealthPoints(20);
    SetMaxCarry(30000);
}

void init(){
    ::init();
}

int eventMove(mixed foo){
    int ret;
    ret = ::eventMove(foo);
    return ret;
}
