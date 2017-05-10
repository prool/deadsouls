#include <lib.h>
#include ROOMS_H

inherit LIB_STORAGE;

void create() {
    ::create();
    SetKeyName("корзина");
    SetId(({"корзина"}));
    SetAdjectives(({"голубая","мусора"}));
    SetShort("корзина для мусора");
    SetLong("Это голубая корзина для мусора, промаркерованная "+
            "буквами \"/dev/null\".");
    SetMass(200);
    SetBaseCost("silver",50);
    SetMaxCarry(999999);
}

int tidy_up(){
    object *inv;
    inv = all_inventory(this_object());
    foreach(object thing in inv){
        if(thing) thing->eventMove(ROOM_FURNACE);
    }
    return 1;
}

int eventReceiveObject(object ob){
    write("Вы выбросили мусор в корзину для мусора.\n");
    call_out((: tidy_up :),1);
    return 1;
}
mixed CanGet(object ob) { return "Крышка не открывается.";}

void init(){
    ::init();
}
