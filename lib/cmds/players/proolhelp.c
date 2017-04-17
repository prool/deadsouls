#include <lib.h>

inherit LIB_DAEMON;

mixed cmd (string str)
{
write("\nProol's russian commands:\nНовые команды, сделанные Прулем\n\nгов строка - говорить строка (только в комнате)\n\n\
кри строка - кричать строка (на весь мир)\n\nProol home: goto /domains/default/room/wiz_hall_prool\n");
return 1;
}

string GetHelp(){
    return ("Syntax: proolhelp\n\n"
            "help by prool\n");
}
