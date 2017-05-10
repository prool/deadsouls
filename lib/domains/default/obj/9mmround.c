#include <lib.h>
#include <vendor_types.h>
inherit "/lib/round";

void create(){
    ::create();
    SetKeyName("патрон 9мм");
    SetId(({"патрон","пуля"}));
    SetAdjectives(({"9 millimeter","9mm","pistol"}));
    SetShort("патрон от пистолета калибра 9мм");
    SetLong("Это патрон от пистолета калибра 9мм. Целый...");
    SetMillimeter(9);
    SetFirearmType("auto");
    SetAmmoType("acp");
    SetVendorType(VT_TREASURE);
}
