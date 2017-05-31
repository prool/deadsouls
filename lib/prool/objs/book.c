#include <lib.h>
#include <vendor_types.h>
inherit LIB_BOOK;

void create(){
    ::create();
    SetKeyName("книга");
    SetId( ({"книга"}) );
    SetAdjectives( ({"книга","книжка"}) );
    SetShort("обычная книга");
    SetLong("Обычная книга с экслибрисом Пруля.");
    SetMass(20);
    SetBaseCost("silver",10);
    SetVendorType(VT_TREASURE);
    SetTitle("Книга");
}
void init(){
    ::init();
}
