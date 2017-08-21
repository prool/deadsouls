/*  /cmds/players/customize.c
 *   переведено Tuor
 */

#include <lib.h>
#include <message_class.h>

inherit LIB_DAEMON;

mixed cmd(string args) {
    mixed tmp;
    string stat;
    int amt;

    if( !args || args == "" ) {
        amt = this_player()->GetCustomStats();
        this_player()->eventPrint("У вас есть " + amt + " очков для "
                "улучшения характеристик.", MSG_SYSTEM);
        return 1;
    }
    amt = to_int((tmp = explode(args, " "))[<1]);
    if( sizeof(tmp) == 1 ) return "Какую характеристику хотите сейчас улучшить?";
    stat = implode(tmp[0..<2], " ");
    tmp = this_player()->eventCustomizeStat(stat, amt);
    if( stringp(tmp) ) return tmp;
    if( !tmp ) return "Не удалось улучшить характеристику.";
    this_player()->eventPrint("Ваша " + stat + " сейчас составляет " + tmp +
            " и у вас есть " +
            this_player()->GetCustomStats() +
            " очков для улучшения.", MSG_SYSTEM);
    return 1;
}

string GetHelp(){
    return ("Синтаксис: улучшить [ХАРАКТЕРИСТИКА КОЛИЧЕСТВО]\n\n"
            "Позволяет вам улучшить ваши характеристики, при "
            "наличии соответствующих очков. "
            "Использование этой команды без аргументов сообщает "
            "сколько очков улучшения у вас сейчас есть.\n"
            "Например: улучшить strength 5"
            "\nВажно! Потраченное не вернуть. Больше вы очков улучшения "
            "не получите.\n"
            "Смотрите также: stats, stat, skills, deviation");
}
