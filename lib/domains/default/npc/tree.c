#include <lib.h>
inherit LIB_NPC;

static void create(){
    npc::create();
    SetKeyName("денежное дерево");
    SetId(({"дерево","денежное","arborus argentum"}));
    SetShort("денежное дерево");
    SetLong("Это легендарное arborus argentum или денежное "+
            "дерево. Его листья это свежие бумажные купюры, а его стручки "+
            "полны звенящих монет. Если вы наберете "+
            "get <amount> <currency>, то несомненно "+
            "сорвете джекпот!");
    SetPacifist(1);
    SetCanBite(0);
    SetLevel(99);
    SetRace("tree");
    SetHealthPoints(99999);
    SetMaxHealthPoints(99999);
    SetPreventGet(1);
}

void init(){
    ::init();
    add_action("make_money","get");
}

int make_money(string str){
    int d1;
    string s1,s2;
    if(!creatorp(this_player()) && !member_group(this_player(),"TEST")) {
        write("Кажется, ваши руки соскальзывают с дерева... как будто "
                "оно знает, что ваши жадные руки не должны получить его монет.");
        return 1;
    }
    if(!str){ write("Что взять?\n"); return 1; }
    if(sscanf(str,"%d %s from %s",d1,s1,s2) > 0){
        if(s1 !="electrum" && s1 != "platinum" &&
                s1 !="gold" && s1 !="cents" &&
                s1 !="dollars" && s1 !="copper" &&
                s1 !="silver"){
            write("Этого вида монет нет в дереве!\n");
            return 1;
        }
        if(s2=="дерево" || s2=="денежное" ||
                s2=="денежное дерево" || s2=="arborus argentum"){
            if(d1 > 1000000){
                write("Вы не можете взять столько денег за раз.\n");
                return 1;
            }
            this_player()->AddCurrency(s1, d1);
            write("Вы взяли "+d1+" "+s1+" из денежного дерева.");
            say(this_player()->GetCapName()+" взял деньги из денежного дерева.");
            return 1;
        }
        return 0;
    }
}
