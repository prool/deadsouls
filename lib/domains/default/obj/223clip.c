#include <lib.h>
#include <vendor_types.h>
inherit LIB_CLIP;

void create(){
    clip::create();
    SetKeyName("патроны .223");
    SetId(({"патроны","магазин"}));
    SetAdjectives(({".223","rifle","caliber","ammo","ammunition"}));
    SetShort("магазин для винтовки калибра .223");
    SetLong("Это магазин для винтовки калибра .223. "+
            "В нем тридцать патронов.");
    SetCaliber(223);
    SetMaxAmmo(30);
    SetAmmoType("nato");
    SetVendorType(VT_TREASURE);
    SetInventory(([
                "/domains/default/obj/223round" : 30,
                ]));
}
void init(){
    ::init();
}
