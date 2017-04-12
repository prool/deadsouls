#include <lib.h>

inherit LIB_DAEMON;

mixed cmd (string str)
{
    write("Вы сказали '"+str+"'\n");
    say(this_player()->GetName()+" сказал: "+str);
    return 1;
}

string GetHelp(){
    return ("Syntax: prool\n\n"
            "test command by prool\n");
}
