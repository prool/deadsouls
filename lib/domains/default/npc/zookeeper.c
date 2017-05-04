#include <lib.h>

inherit LIB_BOT;

static void create() {
    ::create();
    SetKeyName("хранитель зоопарка");
    SetId( ({"хранитель", "робот", "хранитель зоопарка", "механизм"}) );
    SetAdjectives(({"non-player", "non player"}));
    SetShort("хранитель зоопарка");
    SetLong("Вы видите искуссно собранный механизм, который круглосуточно следит за состоянием животных в зоопарке.");
    SetLevel(1);
    SetMelee(1);
    SetRace("android");
    SetGender("male");
    SetMaxClones(3);
}
void init(){
    ::init();
}
