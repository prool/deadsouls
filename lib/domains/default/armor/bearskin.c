#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;
static void create(){
    armor::create();
    SetKeyName("медвежья шкура");
    SetId(({"медвежья шкура","шкура"}));
    SetAdjectives(({"медвежья","толстая","лохматая"}));
    SetShort("толстая, лохматая медвежья шкура");
    SetLong("В эту толстую медвежью шкуру можно облачиться, "+
            "как в одежду. К сожалению подкладка шкуры "+
            "не была задублена, так-что она "+
            "жутко воняет.");
    SetItems( ([
                "подкладка" : "Кожа шкуры не обработана "+
                "и начинает подгнивать."
                ]) );
    SetSmell( ([ "default" : "Пахнет мертвечиной." ]) );
    SetMass(75);
    SetDamagePoints(100);
    SetProtection(BLUNT,1);
    SetProtection(BLADE,10);
    SetProtection(KNIFE,10);
    SetArmorType(A_CLOAK);
}
string GetAffectLong(object ob) {
    if(!ob || !living(ob)) return 0;
    return ob->GetName() + " пахнет смертью и разложением.";
}
