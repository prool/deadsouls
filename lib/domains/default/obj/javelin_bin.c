#include <lib.h>

inherit LIB_STORAGE;

void create() {
    ::create();
    SetKeyName("колчан");
    SetAdjectives( ({"высокий", "metal", "javelin","spear"}) );
    SetId( ({"контейнер"}) );
    SetShort("колчан с копьями");
    SetLong("Этот высокий контейнер нужен, чтобы хранить в нем копья.");
    SetInventory(([
                "/domains/town/weap/javelin" : ({ 1200, 10 }),
                ]));
    SetNoCondition(1);
    SetCanClose(0);
    SetMass(274);
    SetBaseCost("silver",1);
    SetMaxCarry(3500);
    SetNoClean(1);
}

void init(){
    ::init();
}

mixed CanGet(object ob) { return "Колчан не открывается.";}

int CanReceive(object ob) {
    if(!answers_to("javelin",ob)) {
        write("Этот колчан только для копий.");
        return 0;
    }
    else return 1;
}
