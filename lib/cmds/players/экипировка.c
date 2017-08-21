/*  /cmds/players/equipment.c
 *   переведено Tuor
 */

#include <lib.h>
#include <rounds.h>

inherit LIB_DAEMON;

void eventInventory();

    mixed cmd(string args) {
        if( this_player()->GetInCombat() )
            this_player()->SetAttack(0, (: eventInventory :), ROUND_OTHER);
        else eventInventory();
        return 1;
    }

void eventInventory() {
    object *weapons = filter(all_inventory(this_player()), (: $1->GetWielded() :) );
    string *bare_limbs = filter(this_player()->GetLimbs(), (: !sizeof(this_player()->GetWorn($1)) :) );
    object *armors = filter(all_inventory(this_player()), 
            (: $1->GetWorn() && !($1->GetWielded()) :) );
    string ret = "Вы используете: \n";

    foreach(object weapon in weapons){
        string tmp = capitalize(weapon->GetShort());
        string *limbs = ({});
        foreach(string limb in weapon->GetWorn()){
            limbs += ({ "ваша "+limb });
        }
        tmp += " вооружена "+item_list(limbs)+".\n";
        ret += tmp+"\n";
    }

    foreach(object armor in armors){
        string tmp = capitalize(armor->GetShort());
        string *limbs = ({});
        foreach(string limb in armor->GetWorn()){
            limbs += ({ "на вашей "+limb });
        }
        tmp += " надето "+item_list(limbs)+".\n";
        ret += tmp;
    }

    if(sizeof(bare_limbs)){
        ret +="\nСледующие части тела не экипированы: \n";
        ret += capitalize(item_list(bare_limbs)+".");
    }

    write(ret);
}

string GetHelp(){
    return ("Синтаксис: экипировка\n\n"
            "Выводит на экран все, чем вы вооружены и что на вас надето. "
            "Эта команда "
            "длится один раунд боя, если вы находитесь в "
            "бою.");
}
