#include <lib.h>
#include <vendor_types.h>
inherit LIB_BOOK;

void create(){
    ::create();
    SetKeyName("справочник администратора");
    SetId( ({"справочник", "book", "guide", "справочник администратора", "administrators guidebook"}) );
    SetAdjectives( ({"администратора", "admin", "admins", "administrator", "administrators", "reference"}) );
    SetShort("Справочник администратора");
    SetLong("Это справочник администратора AncestryMUD.");
    SetNoCondition(1);
    SetSource("/doc/guide");
    SetMass(20);
    SetBaseCost("silver",10);
    SetVendorType(VT_TREASURE);
    SetTitle("Справочник администратора");
}
void init(){
    ::init();
}
