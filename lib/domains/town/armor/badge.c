#include <lib.h>
#include ROOMS_H
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("пропуск посетителя");
    SetId(({"пропуск посетителя","значок","пропуск","visitor's pass"}));
    SetShort("Пропуск посетителя");
    SetLong("Этот значок на защелке дает пропуск к "+
            "некоторым тестовым зонам, доступным только для билдеров. Злоупотребление "+
            "пропуском приведет к суровому наказанию. Маленькая надпись "+
            "на дне значка гласит: нажмите рычажок");
    SetProperties(([
                "no steal" : 1,
                ]));
    SetMass(1);
    SetBaseCost("silver",500);
    SetArmorType(A_AMULET);
    SetRetainOnDeath(1);
    SetRestrictLimbs( ({ "torso" }) );
}

void init(){
    ::init();
    add_action("nplh","нажать");
}

int nplh(string str){
    if(str=="рычажок"){
        if(present(this_object()->GetKeyName(),this_player() ) ){
            write("Хотя нет ничего лучше дома!\n"+
                    "Вас переместило в какое-то замечательное "+
                    "место...\n");
            this_player()->eventMoveLiving(ROOM_START);
            return 1;
        }
        write("Вы нажали рычажок...но кажется, "+
                "что ничего не происходит.\n");
        return 1;
    }
}

string GetAffectLong(object ob) {
    if(!ob || !living(ob)) return 0;
    return ob->GetName() + " - авторизованный Тестер мира.";
}
