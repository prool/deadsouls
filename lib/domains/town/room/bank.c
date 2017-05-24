#include <lib.h>
inherit LIB_BANK;

int ReadSign();
static void create() {
    bank::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Первый Деревенский Банк");
    SetLong("Это неказистое место является центром финансовой деятельности всей округи. Хотя это и не самое привлекательное учреждение, этому банку доверяют местные жители, которые хранят здесь свои сбережения.\n%^GREEN%^На стене перед вами висит табличка.%^RESET%^");
    SetInventory( ([
        "/domains/town/npc/zoe" : ({60, 1})
      ]) );
    SetItems( ([
        "табличка" : "Эту табличку вы можете прочесть.",
        ({"банк","ервый Деревенский Банк"}) : "Это основное финансовое учреждение "
        "города.",
      ]) );
    SetExits( ([
        "west" : "/domains/town/room/mountain_road.c",
      ]) );
    SetRead( ({"табличка","табличку"}) , (: ReadSign :) );
    SetProperty("no attack", 1);
}
int ReadSign(){
    write( @EndText
- Чтобы открыть здесь счет вам понадобятся минимальные вложения.
Чтобы пользоваться любой услугой банка, вам понадобится сначала
открыть здесь счет (читайте ниже, как это сделать).

- Этот банк предоставляет определенные услуги, такие как, например,
обмен валюты.

Чтобы вести здесь бизнес:

request account from TELLER
request balance from TELLER
ask TELLER to deposit AMOUNT CURRENCY
ask TELLER to withdraw AMOUNT CURRENCY
ask TELLER to exchange AMOUNT CURRENCY for CURRENCY

Примеры:

request account from zoe
request balance from zoe
ask zoe to deposit 100 silver
ask zoe to withdraw 10 silver
ask zoe to exchange 10 gold for silver

EndText
    );
    return 1;
}

void init(){
    ::init();
}
