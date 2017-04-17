#include <lib.h>
#include ROOMS_H
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("пропуск посетителя");
    SetId(({"пропуск посетителя","пропуск","посетителя","жетон"}));
    SetShort("пропуск посетителя зон");
    SetLong("Этот небольшой жетон, который можно прикрепить к одежде, "+
            "позволяет посещать зоны, обычно закрытые для билдеров. Злоупотребление "+
            "пропуском может повлечь наказание. Надпись на дне "+
            "пропуска гласит: нажмите рычажок");
    SetProperties(([
                "no steal" : 1,
                ]));
    SetMass(10);
    SetBaseCost(5000);
    SetDamagePoints(100);
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
            write("Решив, что здесь вам не место!\n"+
                    "Вы перенеслись в мощном вихре куда-то "+
                    "еще...\n");
            this_player()->eventMoveLiving(ROOM_START);
            return 1;
        }
        write("Вы нажали рычажок... но кажется, "+
                "что вы чего-то упустили.\n");
        return 1;
    }
}
string GetAffectLong(object ob) {
    if(!ob || !living(ob)) return 0;
    return ob->GetName() + " авторизованный тестер мира.";
}
