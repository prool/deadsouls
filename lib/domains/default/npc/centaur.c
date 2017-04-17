#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("кентавр");
    SetId(({"нпс","моб","существо","гибрид"}));
    SetAdjectives(({"дикий", "непредсказуемый"}));
    SetShort("кентавр");
    SetLong("Появление этого гибрида человека и коня доподлинно неизвестно, но и в легендах и в жизни эти существа очень дикие и непредсказуемые. И лучше их не провоцировать.");
    SetWanderSpeed(10);
    SetLevel(1);
    SetMelee(1);
    SetRace("centaur");
    SetGender("male");
}
void init(){
    ::init();
}
