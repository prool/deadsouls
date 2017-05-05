#include <lib.h>
#include <vendor_types.h>

inherit LIB_TELLER;


static void create() {
    ::create();
    SetKeyName("зоя");
    SetId( ({ "кассирша","банкир","кассир" }) );
    SetAdjectives( ({ "привлекательная","доброжелательная" }) );
    SetShort("Зоя-кассирша");
    SetLevel(12);
    SetLong("Зоя - привлекательная блондинка с иностранным "
            "акцентом. Она одета в классический деловой "
            "костюм и всем своим видом излучает доброжелательность.");
    SetGender("female");
    SetMorality(40);
    SetRace("human");
    AddCurrency("silver", random(100));
    SetProperty("no bump", 1);
    SetLocalCurrency("silver");
    SetBankName("First Village Bank");
    SetLocalCurrency("silver");
    SetLocalFee(1);
    SetOpenFee(5);
    SetExchangeFee(2);
    SetCurrencies( ({ "copper", "silver", "electrum", "gold", "platinum" }) );


}
void init(){
    ::init();
}
