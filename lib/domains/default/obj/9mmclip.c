#include <lib.h>
#include <vendor_types.h>
inherit LIB_CLIP;

void create(){
    clip::create();
    SetKeyName("патроны 9мм");
    SetId(({"патроны","магазин"}));
    SetAdjectives(({"9мм","девяти","девяти милиметрового"}));
    SetShort("патроны для девяти милиметрового пистолета");
    SetLong("Это магазин с металлическими патронами "+
            "готовый для вставки в пистолет калибра 9мм.");
    SetMillimeter(9);
    SetMaxAmmo(15);
    SetAmmoType("acp");
    SetVendorType(VT_TREASURE);
    SetInventory(([
                "/domains/default/obj/9mmround" : 15
                ]));
}

void init(){
    clip::init();
}
