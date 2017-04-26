/* /secure/cmds/player/afk.c
 *  From the Frontiers LPC library
 *  created by Cratylus, 17Nov96
 */

#include <lib.h>
#include <daemons.h>

inherit LIB_DAEMON;

mixed cmd(string args) {
    int afk;
    afk = this_player()->GetProperty("afk");
    if(afk){
        afk = 0;
        message("system", "Вы вернулись в игру.", this_player() );
    }
    else {
        afk = 1;
        message("system", "Вы отошли от клавиатуры.", this_player() );
    }
    this_player()->SetProperty("afk", afk);
    if(find_object(INSTANCES_D)){
        INSTANCES_D->SendWhoUpdate(this_player()->GetKeyName());
    }
    return 1;
}

string GetHelp() {
    return ("Синтаксис: афк\n\n"
            "Помечает вас флагом 'отошли от клавиатуры'.");
}
