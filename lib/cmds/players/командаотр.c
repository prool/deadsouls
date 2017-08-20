/*  /cmds/player/commandecho.c
 *   переведено Tuor
 */

#include <lib.h>

inherit LIB_DAEMON;

mixed cmd(string str) {
    string *clrs = ({ "red", "green", "yellow", "blue",
            "cyan", "magenta", "black", "white" });
    if( !sizeof(str) )
        return "Синтаксис: командаотр <вкл или выкл или ЦВЕТ>";
    str = lower_case(str);

    if( str != "вкл" && str != "выкл" && member_array(str, clrs) == -1 )
        return "Попробуйте: help командаотр";
    this_player()->SetProperty("commandecho", ( str == "выкл" ? 0 : str ));
    message("system",
            "Режим командаотр "+str+".",
            this_player() );
    return 1;
}

string GetHelp() {
    return ("Синтаксис: командаотр <вкл | выкл | ЦВЕТ>\n\n"
            "Включает или выключает отображение введенных "
            "вами команд в игре. Это полезно только если "
            "вы используете reprompt и/или charmode режимы. "
            "Вы также можете указать цвет, используя один из "
            "следующих: red, green, yellow, blue, cyan, magenta, black, "
            "white. Например:\nкомандаотр blue\n"
            "Смотрите также: reprompt, charmode, репромпт");
}

