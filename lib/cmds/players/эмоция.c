/*    /cmds/player/emote.c
 *    переведено Tuor
 */

#include <lib.h>

inherit LIB_DAEMON;

mixed cmd(string args) {
    if( !creatorp(this_player()) && !avatarp(this_player()) ) {
        if( this_player()->GetStaminaPoints() < 1 )
            return "Вы слишком устали.";
    }
    if( !args || args == "" ) {
        message("my_action", "Вы проявляете эмоцию.", this_player());
		if( this_player()->GetGender() == "female" ) {
        message("other_action", this_player()->GetName() +
                " выглядит эмоциональной.", environment(this_player()),
                ({ this_player() }));
		}
		else {
        message("other_action", this_player()->GetName() +
                " выглядит эмоциональным.", environment(this_player()),
                ({ this_player() }));
		}
        return 1;
    }
    if( args[0] != '\'' ) args = " " + args;
    message("my_action", "Вы проявляете эмоцию: " + this_player()->GetName() + 
            args, this_player());
    message("other_action", this_player()->GetName() + args,
            environment(this_player()), ({ this_player() }) );
    return 1;
}

string GetHelp() {
    return ("Синтаксис: эмоция <сообщение>\n\n"
            "Помещает введенное сообщение сразу после вашего имени.  "
            "Например, \"эмоция плачет.\" будет видна другим в виде "
            "\"Туор плачет.\".  Игроки при каждой эмоции будут терять "
            "очки действий.");
}

