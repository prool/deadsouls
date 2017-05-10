#include <lib.h>
#include <vendor_types.h>
inherit LIB_BOOK;

void create(){
    ::create();
    SetKeyName("справочник игрока");
    SetId( ({"справочник", "handbook", "справочник игрока"}) );
    SetAdjectives( ({"player", "players"}) );
    SetShort("Справочник игрока");
    SetLong("Это справочник игрока. Чтобы читать его, вы должны выбрать определенную главу. Например, 'read chapter 1 in handbook' или 'read index in handbook'");
    SetProperties(([
                "no steal" : 1,
                ]));
    SetMass(3);
    SetBaseCost("silver",10);
    SetVendorType(VT_TREASURE);
    SetTitle("Справочник игрока");
    SetSource("/doc/hbook");
    SetDefaultRead("Попробуйте \"read chapter 1 in handbook\" or "
            "\"read index in handbook\"");

}
void init(){
    ::init();
}
