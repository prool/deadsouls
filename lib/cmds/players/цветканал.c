/*  /cmds/player/chancolors.c
 *   переведено Tuor
 */
 
#include <lib.h>

inherit LIB_DAEMON;

mixed cmd(string str) {
    int what;
    if( !sizeof(str) )
        return "Синтаксис: цветканал <вкл или выкл>";
    str = lower_case(str);
    if( str != "вкл" && str != "выкл" )
        return "Вы можете режим цветканал только 'вкл' или 'выкл'.";
    if(str == "вкл") what = 0;
    else what = 1;
    this_player()->SetNoChanColors(what);
    message("system",
            "Режим цветных каналов "+str+".",
            this_player() );
    return 1;
}

string GetHelp() {
    return ("Синтаксис: цветканал [вкл | выкл]\n\n"
            "Эта команда переключает режим, в котором видны цветные сообщения. \nВажно! Это не распространяется на цветное название канала.");
}

