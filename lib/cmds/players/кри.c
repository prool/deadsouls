#include <lib.h>

inherit LIB_DAEMON;

mixed cmd (string str)
{
    if (str)
	{
    write("Вы крикнули %^BOLD%^%^BLUE%^\""+str+"\"%^RESET%^\n");
    shout(this_player()->GetName()+" крикнул: %^BOLD%^%^BLUE%^\""+str+"\"%^RESET%^");
	}
    else
	{
	write("Вы что-то хотели крикнуть, наверное\n");
	}
    return 1;
}

string GetHelp(){
    return ("Syntax: кри string\n\n"
            "shout string\n");
}
