/* /secure/cmds/players/history.c
 *  переведено Tuor
 */

#include <lib.h>
#include <message_class.h>

inherit LIB_DAEMON;

mixed cmd(string args) {
    int x;
    object player = this_player();
    if(!player) return 0;
    if(player->GetForced()) return 0;

    if( x = to_int(args) ) {
        if( previous_object()->SetHistorySize(x) != x ) {
            if( x < MIN_HISTORY_SIZE )
                return "Размер истории должен быть как минимум " + MIN_HISTORY_SIZE + ".";
            else if( x > MAX_HISTORY_SIZE )
                return "Размер истории не может превышать " + MAX_HISTORY_SIZE +
                    ".";
            else return "Неверный размер истории.";
        }
        else {
            previous_object()->eventPrint("Размер истории установлен в: " + x);
        }
    }
    else {
        string array arr, tmp = ({});
        mapping history;
        int cmd_num, i;

        history = this_player()->GetCommandHist();
        cmd_num = sizeof(history);
        foreach(mixed key, mixed cmd in history) {
            if( !cmd ) continue;
            tmp += ({ sprintf("%:-5d %s", key, cmd) });
        }
        previous_object()->eventPage(tmp, MSG_SYSTEM);
    }
    return 1;
}

string GetHelp(string str) {
    return ("Синтаксис: история\n"
            "        история <РАЗМЕР>\n\n"
            "Эта команда позволяет вам воспроизводить историю ваших команд. " 
            "Это нужно для быстрого воспроизведения введенных вами команд "
            "или для их быстрой модификации.  Размер буфера "
            "ваших команд " + MIN_HISTORY_SIZE + ", но "
            "может быть увеличен до " + MAX_HISTORY_SIZE + ", если вы хотите. "
            "Вы можете изменить размер буфера, введя число в качестве параметра "
            "команды 'история'.  Без аргументов команда 'история' "
            "просто выводит команды из буфера на экран.\n\n"
            "Можно использовать следующий синтаксис для "
            "команд из буфера:\n"
            "\t!!\t\tвыполнить последнюю команду\n"
            "\t!#\t\tвыполнить команду номер #\n"
            "\t!-#\t\tвыполнить #нную команду\n"
            "\t^old^new\tзаменить 'old' фразу на 'new' в последней команде и "
            "выполнить\n"
            "\t!#^old^new\tтоже самое, что и выше, только для команды номер #\n"
            "\t!#s/old/new/g\tтоже самое, что и выше, только заменяет "
            "все 'old' фразы в команде\n\n"
            "Смотрите также: alias, nickname");
}
