/*  /cmds/players/inventory.c
 *   переведено Tuor
 */

#include <lib.h>
#include <rounds.h>
#include <message_class.h>

inherit LIB_DAEMON;

void eventInventory();

    mixed cmd(string args) {
        if( this_player()->GetInCombat() )
            this_player()->SetAttack(0, (: eventInventory :), ROUND_OTHER);
        else eventInventory();
        return 1;
    }

void eventInventory() {
    mapping borg;
    string *items, *wieldeds, *worns, *shorts;
    string ret;
    int i;

    items = map(filter(all_inventory(this_player()), 
                (: !($1->GetInvis(this_player())) &&
                 !($1->GetWorn()) :)),
            (: $1->GetEquippedShort() :));
    wieldeds = map(filter(all_inventory(this_player()),
                (: !($1->GetInvis(this_player())) &&
                 ($1->GetWielded()) :)),
            (: $1->GetEquippedShort() :));
    worns = map(filter(all_inventory(this_player()),
                (: !($1->GetInvis(this_player())) &&
                 !($1->GetWielded()) && $1->GetWorn() :)),
            (: $1->GetEquippedShort() :));
    shorts = items + wieldeds + worns;
    if( !(i = sizeof(shorts)) ) {
        message("system", "Вы не несете ничего.", this_player());
        return;
    }
    if( i == 1 ) ret = "Вы несете только эту вещь:\n";
    else ret = "Вы несете следующие вещи:\n";
    foreach(shorts in ({ items, wieldeds, worns })){
        i = sizeof(shorts);
        if(!i) continue;
        borg = ([]);
        while(i--) if( shorts[i] ) borg[shorts[i]]++;
        i = sizeof(shorts = keys(borg));
        while(i--) ret += capitalize(consolidate(borg[shorts[i]], 
                    shorts[i]))+"\n";
    }
    message("look", ret, this_player());
    if(!this_player()->GetInvis() && 
            !environment(this_player())->GetProperty("meeting room"))
        message(MSG_ANNOYING, this_player()->GetName() + " проверяет имущество" +
                possessive(this_player()) + ".", 
                environment(this_player()), ({ this_player() }));
}

string GetHelp() {
    return ("Синтаксис: инвентарь\n\n"
            "Выводит на экран вещи, которые вы несете с собой. Эта команда "
            "занимает один раунд боя, если вы используете ее в "
            "бою.");
}
