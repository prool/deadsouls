/*  /cmds/player/brief.c
 *   переведено Tuor
 */

#include <lib.h>

inherit LIB_DAEMON;

    mixed cmd(string str) {
        if( !sizeof(str) )
            return "Синтаксис: краткий <вкл или выкл>";
        str = lower_case(str);
        if( str != "вкл" && str != "выкл" )
            return "Вы можете режим краткий только 'вкл' или 'выкл'.";
        this_player()->SetBriefMode(str == "вкл");
        message("system",
                "Режим краткий "+str+".",
                this_player() );
        return 1;
    }

string GetHelp() {
    return ("Синтаксис: краткий [вкл | выкл]\n\n"
            "Эта команда позволяет вам включить или выключить краткие описания "
            "комнат.\nСмотрите также: env");
}

