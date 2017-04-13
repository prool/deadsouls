#include <lib.h>

inherit LIB_DAEMON;

mixed cmd (string str)
{
    write("%^BOLD%^%^CYAN%^prool v.0.2%^RESET%^");
    shout("Uuuuuuuuuuuuuuuuuu!");
    return 1;
}

string GetHelp(){
    return ("Syntax: prool\n\n"
            "test command by prool\n");
}
