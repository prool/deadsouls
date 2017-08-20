/*    /cmds/player/mute.c
 *    переведено Tuor
 */

#include <lib.h>

inherit LIB_DAEMON;

mixed cmd(string str) {
    string which, type;
    string *validtypes = ({ "удаленные", "местные", "все" });
    if( !sizeof(str) )
        return "Синтаксис: заглушить <вкл или выкл> [удаленные или местные]";
    str = lower_case(str);
    sscanf(str,"%s %s",which, type);
    if(!type) type = "все";
    else str = which;
    if( str != "вкл" && str != "выкл" )
        return "Режим заглушки может быть только 'вкл' или 'выкл'.";
    if( member_array(type, validtypes) == -1 )
        return "Допустимые типы заглушки: удаленные, местные, все.";
    this_player()->SetMuted(type, (str == "вкл"));
    message("system",
            "Режим заглушки переведен в состояние "+str+" для каналов "+type+".",
            this_player() );
    return 1;
}

string GetHelp() {
    return ("Синтаксис: заглушить вкл [ удаленные | местные ]\n"
            "        заглушить выкл [ удаленные | местные ]\n\n"
            "Эта команда позволяет вам избежать сообщений каналов.\n"
            "Вы можете заглушить все каналы: заглушить вкл\n"
            "Чтобы заглушить только intermud каналы: заглушить вкл удаленные\n"
            "Смотрите также: gag, env");
}
