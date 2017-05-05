#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("пегас");
    SetId( ({"конь", "жеребец", "пегас"}) );
    SetAdjectives( ({"великолепный", "белоснежный", "крылатый"}) );
    SetShort("пегас");
    SetLong("Этот великолепный белоснежный жеребец обладает двумя восхитительными крыльями, способными поднять его в воздух.");
    SetLevel(5);
    SetMount(1);
    SetRace("pegasus");
    SetStat("strength", 50);
    SetGender("male");
    SetMelee(1);
    SetAction(5, ({ 
                "Пегас фыркнул.", "Пегас взмахнул крыльями.", 
                "Пегас помахивает своим хвостом.",
                "Пегас оглядывается по сторонам."}));
}
void init(){
    ::init();
}
