#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("тога лекаря");
    SetId(({"тога"}));
    SetAdjectives(({"длинная","белая","comfotable"}));
    SetShort("длинная белая тога");
    SetLong("Вы видите белую тогу, длинной до пола. Такие носили раньше "
            "древние политики, сейчас же их носят разве что лекари.");
    SetMass(75);
    SetBaseCost("silver",100);
    SetProtection(BLUNT,1);
    SetProtection(BLADE,10);
    SetProtection(KNIFE,10);
    SetArmorType(A_CLOAK);
}

void init(){
    ::init();
}
