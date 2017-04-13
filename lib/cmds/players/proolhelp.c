#include <lib.h>

inherit LIB_DAEMON;

mixed cmd (string str)
{
write("Новые команды, сделанные Прулем\n\nгов строка - говорить строка (только в комнате)\n\nкри строка - кричать строка (на весь мир)");
return 1;
}

string GetHelp(){
    return ("Syntax: proolhelp\n\n"
            "help by prool\n");
}
