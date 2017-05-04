#include <lib.h>

inherit LIB_DAEMON;
inherit LIB_VERB;

mixed cmd (string str)
{
write("prool test command");
    foreach(object ob in all_inventory(environment(this_player()))){
	write(ob->GetName());
	if (ob->GetMagaral()) write("Magaral non zero");
	else write("Magaral zero");
	
//	ob->eventGet(this_player());
}
return 1;
}

string GetHelp(){
    return ("Syntax: prool\n\n"
            "test command by prool\n");
}
