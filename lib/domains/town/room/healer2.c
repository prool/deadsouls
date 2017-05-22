#include <lib.h>
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Кладовая гильдии лекарей");
    SetLong("В этой небольшой комнате содержатся припасы гильдии.");
    SetInventory(([
                "/domains/town/meals/claritin" : 20,
                "/domains/town/obj/slip_heal" : 100,
                "/domains/town/obj/slip_regenerate" : 10,
                "/domains/town/obj/slip_excise" : 10,
                "/domains/town/meals/potion_antidote" : 20,
                ]));
    SetExits( ([ 
                ]) );

}
int CanReceive(object sneak) {
    object *living_stack = get_livings(sneak);
    if(!living_stack || !arrayp(living_stack)) living_stack = ({ sneak });
    foreach(object ob in living_stack){
        if(living(ob) && !creatorp(ob) &&
                !member_group(ob,"TEST")) {
            message("info","Эта кладовая только для членов гильдии лекарей.", ob);
            return 0;
        }
    }
    return 1;
}

void init(){
    ::init();
}
