#include <lib.h>

inherit LIB_DAEMON;

mixed cmd (string str)
{
write("Новые команды, сделанные Прулем\n\nгов строка - говорить строка\n\n");
return 1;
}

string GetHelp(){
    return ("Syntax: proolhelp\n\n"
            "help by prool\n");
}
