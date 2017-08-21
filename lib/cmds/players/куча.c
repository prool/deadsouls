/*    /cmds/player/queue.c
 *    переведено Tuor
 */

#include <lib.h>
#include <daemons.h>

inherit LIB_DAEMON;

mixed cmd(string args) {
    string *cmds;
    if(!sizeof(args)){
        write("Попробуйте: help куча");
        return 1;
    }
    cmds = explode(args, ";");
    foreach(string cmnd in cmds){
        if(sizeof(cmnd)){
            write("Команды в куче: "+cmnd);
            this_player()->eventQueueCommand(cmnd);
        }
    }
    this_player()->eventExecuteQueuedCommands();
    return 1;
}

string GetHelp(){
    return ("Синтаксис: куча <команда1;команда2>\n\n"
            "Собирает команды для исполнения в кучу по порядку.");
}
