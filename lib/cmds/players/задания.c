/*    /cmds/player/quests.c
 *    переведено Tuor
 */
 
#include <lib.h>

inherit LIB_DAEMON;

mixed cmd(string str) {
    string ret;
    object dude;

    if(str && !creatorp(this_player()) ) {
        if(!find_player(str) || find_player(str) != this_player()){ 
            write("Вы можете посмотреть информацию только по своим заданиям.");
            return 1;
        }
    }
    if(str && !find_player(str)){
        write("Этого игрока сейчас нет в игре.");
        return 1;
    }
    if(str) dude = find_player(str);
    else dude = this_player();
    if(!sizeof(dude->GetQuests())){
        if(dude == this_player()) write("Вы не завершили ни одного задания.");
        else write(dude->GetName()+" не завершил ни одного задания.");
        return 1;
    }

    if(dude == this_player()) ret = "Вы завершили следующие задания:\n";
    else ret = dude->GetName()+" завершил следующие задания:\n";

    ret += "----------------------------------------\n";

    foreach(string key, mapping val in dude->GetQuests()){
        ret += val["Описание"] + "\n";
    }
    write(ret);
    return 1;
}

string GetHelp(){
    return ("Синтаксис: задания\n\n"
            "Эта команда выводит список заданий, которые вы завершили.");
}
