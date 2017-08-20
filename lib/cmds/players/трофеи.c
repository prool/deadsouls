/*  /cmds/players/kills.c
 *   переведено Tuor
 */

#include <lib.h>

inherit LIB_DAEMON;

mapping kills = ([]);

mixed cmd(string args) {
    string *stats;
    string killfile, ret, tmp, name;
    int i, x, y;

    name = lower_case(this_player()->GetKeyName());
    killfile = "/save/kills/"+name[0..0]+"/"+name;
    if(!file_exists(killfile)) {
        write("На вашей совести нет убийств.");
        return 1;
    }
    kills = restore_variable(read_file(killfile));
    if(!sizeof(kills)){
        write("Вы не причинили вред ни одной живой душе.");
        return 1;
    }
    ret = "Вы " +this_player()->GetShort() + ", ваш уровень " +
        this_player()->GetLevel();
    if( (tmp = this_player()->GetClass()) ) 
        ret += " " + capitalize(tmp);
    else ret += " Скиталец";
    ret += " (" + this_player()->GetRace() + ")\n";
    ret+= "В вашем листе убийств следующие жертвы:\n\n";
    stats = map(keys(kills),
            (: sprintf("%:-20s: %:-1i", $1, 
                       kills[$1]) :));
    i = sizeof(stats);
    while(i--) if( (y = strlen(stats[i])) > x ) x = y;
    x = ((int *)this_player()->GetScreen())[0]/(x+2);
    ret += format_page(stats, x);
    message("system", ret, this_player());
    return 1;
}

string GetHelp() {
    return ("Синтаксис: трофеи\n\n"
            "Выводит список ваших достижений.");
}
