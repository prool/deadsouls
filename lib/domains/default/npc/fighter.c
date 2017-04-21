#include <lib.h>
inherit LIB_NPC;

static void create(){
    npc::create();
    SetKeyName("воин");
    SetId( ({"человек","нпс","воин","боец"}) );
    SetShort("воин");
    SetLong("Это высокий человек-воин. Его рельефные мускулы "+
            "четко видны даже под доспехами. Его лицо сплошь покрыто "+
            "синими таттуровками.");
    SetClass("fighter");
    SetLevel(10);
    SetCustomXP(350);
    SetRace("human");
    SetStat("strength", 30);
    SetGender("male");
    SetInventory(([
                "/domains/default/armor/chainmail.c" : "wear chainmail",
                "/domains/default/weap/sharpsword.c" : "wield sword"
                ]));
    SetCurrency( ([
                "silver" : 100,
                ]) );
    SetHealthPoints(549);
    SetMaxHealthPoints(550);
}
void init(){
    ::init();
}
