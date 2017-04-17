#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_WORN_STORAGE;

static void create(){
    ::create();
    SetKeyName("хламида волшебника");
    SetAdjectives( ({"волшебная", "просторные", "бесформенные"}) );
    SetId(({"хламида","волшебника","одеяния"}));
    SetShort("хламида волшебника");
    SetLong("Это просторные бесформенные одеяния, которые так любят волшебники. В ней много карманов и скрытых областей, где можно прятать голубей или кроликов.");
    SetProperties(([
                "gamma" : 3,
                "no steal" : 1,
                ]));
    SetCanClose(1);
    SetMaxCarry(5000);
    SetMass(200);
    SetBaseCost("silver",100);
    SetDamagePoints(100);
    SetArmorType(A_CLOAK);
    SetProtection(MAGIC, 10);
    SetProtection(COLD, 10);
}
void init(){
    ::init();
}
