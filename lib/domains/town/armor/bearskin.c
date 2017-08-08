#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("мудвежья шкура");
    SetId(({"медвежья шкура","шкура"}));
    SetAdjectives(({"толстая","лохматая"}));
    SetShort("медвежья шкура");
    SetLong("Эту толстую медвежью шкуру можно носить, "+
            "как доспех. К сожалению, она практически "+
            "не обработана и испускает неприятный "+
            "запах.");
    SetItems( ([
                "кожа" : "Она не обработана и начинает "+
                "разлагаться."
                ]) );
    SetSmell( ([ "default" : "Пахнет смертью." ]) );
    SetMass(75);
    SetBaseCost("silver",10);
    SetProtection(BLADE,5);
    SetProtection(KNIFE,5);
    SetArmorType(A_CLOAK);
}

string GetAffectLong(object ob) {
    if(!ob || !living(ob)) return 0;
    return ob->GetName() + " исходит запах смерти и разложения.";
}

void init(){
    ::init();
}
