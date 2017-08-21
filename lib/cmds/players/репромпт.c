/*    /cmds/player/reprompt.c
 *    переведено Tuor
 */

#include <lib.h>

inherit LIB_DAEMON;

    mixed cmd(string str) {
        if( !sizeof(str) )
            return "Синтаксис: репромпт <вкл или выкл>";
        str = lower_case(str);
        if( str != "вкл" && str != "выкл" )
            return "Вы можете переключить репромпт только в положение 'вкл' или 'выкл'";
        this_player()->SetProperty("reprompt", ( str == "вкл" ? 1 : 0 ));
        message("system",
                "Репромпт переключен в "+str+".",
                this_player() );
        return 1;
    }

string GetHelp() {
    return ("Синтаксис: репромпт [вкл | выкл]\n\n"
            "Определяет будет ли обновляться ваша строка состояния "
            "при получении сообщений. Не все клиенты для игры поддерживают это. "
            "Имейте ввиду, незавершенные команды в этом режиме могут "
            "странно выглядеть.\n"
            "Смотрите также: charmode, prompt, env, промпт");
}

