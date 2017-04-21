#include <lib.h>

inherit LIB_SENTIENT;
inherit LIB_MOUNT;
inherit LIB_DOMESTICATE;

static void create() {
    sentient::create();
    SetKeyName("жеребец");
    SetId(({"жеребец","рослый жеребец"}));
    SetShort("рослый жеребец");
    SetLong("Рослый и хорошо сложенный, жеребец может лягнуть так, что мало не покажется.");
    SetWimpy(50);
    SetLevel(5);
    SetRace("horse");
    SetGender("male");
    SetMelee(1);
    SetAction(5, ({ 
                "Жеребец фыркнул.", "Вы слышите лошадиное ржание.", 
                "Жеребец помахивает своим хвостом, отгоняя назойливых мух.",
                "Жеребец оглянулся."}));
    SetNoClean(1);
}
void init(){
    ::init();
}
