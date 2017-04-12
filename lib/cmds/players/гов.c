#include <lib.h>

inherit LIB_DAEMON;

mixed cmd (string str)
{
    if (str)
	{
    write("Вы сказали '"+str+"'\n");
    say(this_player()->GetName()+" сказал: "+str);
	}
    else
	{
	write("Вы что-то хотели сказать, наверное\n");
	}
    return 1;
}

string GetHelp(){
    return ("Syntax: гов string\n\n"
            "say string\n");
}
