#include <lib.h>

inherit LIB_STORAGE;

void create() {
    ::create();
    SetKeyName("шкаф");
    SetId( ({ "шкаф" }) );
    SetAdjectives( ({ "выставочный","стеклянный" }) );
    SetShort("выставочный стеклянный шкаф");
    SetLong("Это стеклянный шкаф, предназначенный для размещения и отображения огнестрельного оружия.");
    SetInventory(([
                "/domains/default/weap/m16rifle" : 1,
                "/domains/default/weap/9mil" : 1,
                "/domains/default/weap/357pistol" : 1,
                "/domains/default/weap/prifle" : 1,
                ]));
    SetOpacity(0);
    SetCanClose(1);
    SetClosed(1);
    SetMass(274);
    SetBaseCost("silver",1);
    SetMaxCarry(1500);
}
void init(){
    ::init();
}

int CanReceive(object ob) {
    if(!inherits(LIB_FIREARM,ob)) {
        write("Этот шкаф только для огнестрельного оружия.");
        return 0;
    }
    else return 1;
}

mixed CanGet(object ob) { return "Дверца не открывается.";}
