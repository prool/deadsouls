#include <lib.h>
#include <vendor_types.h>
inherit LIB_BOOK;

void create(){
    ::create();
    SetKeyName("справочник билдера");
    SetId( ({"текст","путеводитель", "книга", "справочник", "справочник билдера"}) );
    SetAdjectives( ({"билдера", "билдер"}) );
    SetShort("Справочник билдера");
    SetLong("Это справочник по чудесному миру AncestryMUD для билдеров.");
    SetNoCondition(1);
    SetSource("/doc/bguide");
    SetMass(20);
    SetVendorType(VT_TREASURE);
    SetTitle("Builder's Guidebook");
}
void init(){
    ::init();
}
