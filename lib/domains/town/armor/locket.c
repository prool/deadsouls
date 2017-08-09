#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_WORN_STORAGE;

static void create(){
    ::create();
    SetKeyName("ожерелье");
    SetId(({"ожерелье","chain" "locket"}));
    SetAdjectives(({"серебряное","braided","finest"}));
    SetShort("серебряное ожерелье");
    SetLong("Вы видите цепь из переплетенных серебряных колец с небольшим медальоном.");  
    SetMass(50);
    SetMaxCarry(300);
    SetBaseCost("silver",1);
    SetProtection(BLUNT,1);
    SetProtection(BLADE,1);
    SetProtection(KNIFE,1);
    SetArmorType(A_COLLAR);
    SetItems(([
      ({"медальон"}) : "На нем выгравировано имя любимого Бранди человека.",
   ])); 
}

void init(){
    ::init();
}
