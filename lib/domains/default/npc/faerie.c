#include <position.h>
#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("фея");
    SetAdjectives( ({"хрупкая", "красивая", "сказочная", "иллюзорная", "крохотная"}) );
    SetId( ({"фея", "фэйри"}) );
    SetShort("маленькая изящная фея");
    SetLong("Это создание выглядит как крохотная девушка с крыльями стрекозы. Она кажется хрупкой и иллюзорной, а еще она сказочно красива.");
    SetPosition(POSITION_FLYING);
    SetLevel(1);
    SetMelee(1);
    SetRace("faerie");
    SetMaxHealthPoints(50);
    SetGender("female");
}
void init(){
    ::init();
}
