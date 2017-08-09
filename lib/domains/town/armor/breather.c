#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit "/domains/default/armor/breather";

string LongD(){
    string ret = "Это замечательное небольшое устройство вставляется в "+
        "рот и обеспечивает носящего его постоянным притоком свежего "+
        "воздуха. Его текущий заряд: "+
        to_int(percent(charge,maxcharge))+" %.";
    return ret;
}

static void create(){
    ::create();
    SetKeyName("дыхательная маска");
    SetId(({"маска","дыхательная","a98","apparatus","device"}));
    SetAdjectives(({"a98","breathing"}));
    SetShort("дыхательная маска");
    SetLong( (: LongD :) );
    SetMass(30);
    SetBaseCost("silver",900);
    SetArmorType(A_CUSTOM);
    SetRestrictLimbs( ({ "head"}) );
    AddSave( ({ "charge" }) );
    SetCharge(100);
    SetMaxCharge(100);
}

void init(){
    ::init();
}
