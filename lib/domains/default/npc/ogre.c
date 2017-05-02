#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("огр");
    SetAdjectives( ({"ужасный", "непривлекательный", "вонючий"}) );
    SetId( ({"огр", "монстр"}) );
    SetShort("ужасный огр");
    SetLong("Это совершенно не привлекательный монстр. Он в два раза выше и толще человека и у него огромное сальное пузо. А по его грязной шкуре снуют какие-то мерзкие насекомые.");
    SetLevel(1);
    SetMelee(1);
    SetRace("ogre");
    SetGender("male");
}
void init(){
    ::init();
}
