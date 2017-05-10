#include <lib.h>
#include <vendor_types.h>
inherit LIB_BOOK;

void create(){
    ::create();
    SetKeyName("инструкция билдера");
    SetId( ({"manual", "инструкция", "инструкция билдера"}) );
    SetAdjectives( ({"creator", "билдера", "coder", "coders"}) );
    SetShort("Инструкция билдера");
    SetLong("Это инструкция для билдеров и администраторов. "
            "Чтобы читать его, вы должны выбрать определенную главу. Например, \"read "
            "chapter 1 in manual\".\n Если вы новичок в программировании, вы должны "
            "начать с chapter 31.");
    SetNoCondition(1);
    SetProperties(([
                "no steal" : 1,
                ]));
    SetMass(20);
    SetBaseCost("silver",10);
    SetVendorType(VT_TREASURE);
    SetTitle("Инструкция билдера");
    SetSource("/doc/manual");
    SetDefaultRead("Попробуйте \"read chapter 1 in manual\" или "
            "\"read index in manual\"\n"
            "Новички рекомендуется ознакомиться с Quick Creation "
            "System, описанной в chapter 31");
}
void init(){
    ::init();
}
