#include <lib.h>

inherit LIB_CHAIR;

static void create() {
    chair::create();
    SetKeyName("кресло");
    SetId("кресло");
    SetAdjectives( ({ "вращающееся", "небольшое", "черное" }) );
    SetShort("вращающееся кресло");
    SetLong("Это небольшое вращающееся кресло с черной кожаной "+
            "обивкой.");
    SetMass(1500);
    SetDollarCost(15);
    SetMaxSitters(1);
}
void init(){
    add_action("swivel","вращаться");
}

int swivel(string str){
    int hit,i;
    object *dupes;
    dupes = get_dupes(this_object(),environment(this_object()) );
    if(!str || str =="" || str == "кресле" || str == "в кресле"){
        hit = 42;
        for(i=0;i<sizeof(dupes);i++){
            if( member_array(this_player(),dupes[i]->GetSitters()) != -1) hit = 7;
            if( member_array(this_player(),this_object()->GetSitters()) != -1) hit = 7;
        }
        if( hit == 7) {
            write("Вы начали вращаться в кресле! Круто!");
            say(this_player()->GetName()+" завращался в "+possessive(this_player())+" "+
                    "кресле, заорав \"Круто!!!\"");
            return 1;
        }
        else { write("Вы не сидите во вращающемся кресле."); }
    }
    if(hit == 42) return 1;
    else return 0;
}

mixed CanGet(object ob) { return "Кресло не двигается с места.";}
