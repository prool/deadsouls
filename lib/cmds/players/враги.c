/*    /cmds/player/enemies.c
 *    переведено Tuor
 */

#include <lib.h>

inherit LIB_DAEMON;
string *foenames = ({});

mixed cmd(string str) {
    object *foes = ({});
    object ob;
    string ret;
    foenames = ({});
    if(sizeof(str) && !creatorp(this_player())){
        if(find_player(lower_case(str)) != this_player())
            return "Вы можете знать только своих врагов.";
    }
    if(!str) str = this_player()->GetKeyName();
    ob = find_player(lower_case(str));
    if(!ob) return "Такой игрок не найден.";
    foes = ob->GetEnemies();
    if(!sizeof(foes)){
        ret = "Никто не затаил зла на тебя, "+capitalize(str)+".";
    }
    else {
        ret = "На тебя затаили зло: ";
        filter(foes, (: foenames += ({$1->GetShort()}) :) );
        ret += implode(foenames, ", ")+".";
    }
    return ret;
}

string GetHelp() {
    return ("Синтаксис: враги\n\n"
            "Эта команда выводит тех персонажей, с которыми нужно держать ухо востро.");
}

