#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("разноцветный жилет");
    SetId(({"жилет"}));
    SetAdjectives(({"goofy","goofy-looking", "goofy looking", "paisley","разноцветный","hippie","hippy","psychedelic"}));
    SetShort("разноцветный жилет");
    SetLong("Этот жилет раскрашен каким-то ненормальным в самые ядовитые цвета. Долгое смотрение на него вызвает боль в глазах.");
    SetMass(5);
    SetBaseCost("silver",1);
    SetProtection(BLUNT,1);
    SetProtection(BLADE,1);
    SetProtection(KNIFE,1);
    SetArmorType(A_VEST);
}

void init(){
    ::init();
}
