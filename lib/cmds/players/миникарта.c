/*  /cmds/players/minimap.c
 *   переведено Tuor
 */

#include <lib.h>

inherit LIB_DAEMON;

mixed cmd(string args) {
#if MINIMAP
    int status = this_player()->GetProperty("minimapping");
    string sstatus = " ";
    if(!status) sstatus = " не ";
    if(!args){
        write("Вы"+sstatus+"картографируете.");
        return 1;
    }
    if(args == "вкл"){
        if(status) write("Вы уже картографируете.");
        else write("Вы активировали картографирование.");
        this_player()->SetProperty("minimapping", 1);
        return 1;
    }

    if(args == "выкл"){
        if(!status) write("Вы уже не картографируете.");
        else write("Вы отключили картографирование.");
        this_player()->SetProperty("minimapping", 0);
        return 1;
    }

    write("Попробуйте: help миникарта");
    return 1;
#else
    write("Эта опция отключена.");
    return 1;
#endif
}

string GetHelp() {
    return ("Синтаксис: миникарта [вкл | выкл]\n\n"
            "Если эта опция включена, то вам рисуется миникарта "
            "вместе с описанием комнаты.\nСмотрите также: "
            "env, terminal, brief, mute, gag, режим, краткий.");
}
