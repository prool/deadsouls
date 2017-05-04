#include <position.h>
#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("слизень");
    SetId( ({"брюхоногий"}) );
    SetAdjectives( ({"большой", "толстый", "садовый"}) );
    SetShort("скользский слизень");
    SetLong("Вы видите большого толстого садового слизняка. Какая мерзость!");
    SetAutoStand(0);
    SetPosition(POSITION_LYING);
    SetLevel(1);
    SetMelee(1);
    SetRace("slug");
    SetMaxHealthPoints(5);
    SetGender("male");
}
void init(){
    ::init();
}
