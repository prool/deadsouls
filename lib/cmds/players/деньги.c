/*  /cmds/players/money.c
 *   переведено Tuor
 */

#include <lib.h>

inherit LIB_DAEMON;

mixed cmd(string str) {
    string *currs;
    string borg;
    int i, tmp;

    if(str) return 0;  /* to allow the wiz command to work */
    currs = this_player()->GetCurrencies();
    currs = filter(currs, (: this_player()->GetCurrency($1) > 0 :));
    if( !currs || !sizeof(currs) ) {
        write("Вы - бомж.");
        say(this_player()->GetName()+" без единой монетки в карманах.");
        return 1;
    }
    say(this_player()->GetName()+" роется в "+
            possessive(this_player())+" карманах в поисках денег.");
    message("my_action", "В ваших карманах вы нашли "+
            ((sizeof(currs) > 1) ? "следующие деньги монеты: " : "только: "), this_player());
    for(borg = "", i=0, tmp = sizeof(currs); i<tmp; i++) {
        borg += ((this_player()->GetCurrency(currs[i]))+" "+currs[i]);
        if(i == tmp-1) borg +=(".\n");
        else if(tmp > 2 && i == tmp-2) borg += (", и ");
        else if(tmp == 2) borg +=(" и ");
        else borg +=(", ");
    }
    message("my_action", borg, this_player());
    return 1;
}

string GetHelp() {
    return ("Синтаксис: деньги\n\n"
            "Позволяет вам обыскивать свои карманы в поисках "
            "различных денежных единиц.");
}
