#include <lib.h>
#include <vendor_types.h>
inherit LIB_ROUND;


void create(){
    round::create();
    SetKeyName("патрон .223");
    SetId(({"патрон","гильза"}));
    SetAdjectives(({".223","caliber","rifle","m16","M16","m-16","M-16"}));
    SetShort("патрон калибра .223");
    SetLong("Это патрон калибра .223, вероятно от шутрмовой винтовки M-16. "+
            "Небольших размеров, он содержит мощный заряд. Несомненно, "+
            "что он обладает большой убойной силой.");
    SetCaliber(223);
    SetFirearmType("auto");
    SetAmmoType("nato");
    SetVendorType(VT_TREASURE);
}
void init(){
    ::init();
}
