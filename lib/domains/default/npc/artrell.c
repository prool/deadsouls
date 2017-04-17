#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("артрел");
    SetAdjectives( ({"членистоногое"}) );
    SetId(({"нпс","моб","насекомое","существо"}));
    SetShort("артрел");
    SetLong("Это существо напоминало бы человека, если бы не его хитин и четыре лапы с несколькими сочленениями. Оно кажется слегка тоньше и меньше взрослого мужчины, но к нему не хочется прикасаться. Это самое большое насекомое из тех, что вы видели.");
    SetLevel(1);
    SetRace("artrell");
    SetGender("male");
}
void init(){
    ::init();
}
