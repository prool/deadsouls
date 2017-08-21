/*  /cmds/players/flee.c
 *   переведено Tuor
 */

#include <lib.h>

inherit LIB_DAEMON;

mixed cmd(string str) {
    if(!(this_player()->GetInCombat())){
        write("Вы сейчас не в бою.");
        return 1;
    }
    this_player()->eventWimpy("go out");
    return 1;
}

string GetHelp() {
    return ("Синтаксис: бежать\n\n"
            "Эта команда используется, если вам спешно нужно покинуть бой.\n"
            "Эта команда не работает для билдеров.");
}
