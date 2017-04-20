#include <lib.h>

inherit LIB_DAEMON;
inherit LIB_VERB;

mixed cmd (string str)
{
write("prool:");
    foreach(object ob in all_inventory(environment(this_player()))){
	write(ob->GetName());

	ob->eventGet(this_player());

}
}

string GetHelp(){
    return ("Syntax: prool\n\n"
            "test command by prool\n");
}
