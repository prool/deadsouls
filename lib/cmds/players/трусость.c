/*    /cmds/player/wimpy.c
 *    переведено Tuor
 */

#include <lib.h>
#include <message_class.h>

inherit LIB_DAEMON;

mixed cmd(string args) {
    int percentage;
    string cmd;

    if( !args || args == "" ) {
        percentage = this_player()->GetWimpy();
        cmd = this_player()->GetWimpyCommand();
        if( !percentage )
            this_player()->eventPrint("Вы отключили режим трусости.", MSG_SYSTEM);
        else this_player()->eventPrint("Процентное соотношение: " + percentage + "%\n"
                "Команда: " + cmd, MSG_SYSTEM);
        return 1;
    }
    if( args == "0" ) {
        percentage = 0;
        cmd = 0;
    }
    else if( percentage = to_int(args) ) cmd = 0;
    else if( args == "вкл" ) {
        percentage = 23;
        cmd = 0;
    }
    else if( args == "выкл" ) {
        percentage = 0;
        cmd = 0;
    }
    else {
        percentage = 0;
        cmd = args;
    }
    if( !cmd ) {
        if( !percentage ) {
            this_player()->SetWimpy(0);
            this_player()->eventPrint("Режим трусости сейчас отключен!  Вы бесстрашны!",
                    MSG_SYSTEM);
            return 1;
        }
        if( percentage > 30 ) {
            this_player()->eventPrint("Вы не можете установить режим трусости больше "
                    "30%.", MSG_SYSTEM);
            return 1;
        }
        else if( percentage < 1 ) return "Это не допустимое процентное соотношение!";
        this_player()->SetWimpy(percentage);
        if( percentage > 20 ) {
            this_player()->eventPrint("Каков знаток!  Настоящий крепкий орешек!",
                    MSG_SYSTEM);
            return 1;
        }
        else if( percentage > 10 ) {
            this_player()->eventPrint("Вы осторожный малый!", MSG_SYSTEM);
            return 1;
        }
        else {
            this_player()->eventPrint("Вы смелы, но не глупы!",
                    MSG_SYSTEM);
            return 1;
        }
    }
    this_player()->SetWimpyCommand(cmd);
    this_player()->eventPrint("Вы будете выполнять команду: \"" + cmd +
            "\" при активации режима трусости.", MSG_SYSTEM);
    return 1;
}

string GetHelp(){
    return ("Синтаксис: трусость [вкл | выкл | ПРОЦЕНТЫ | КОМАНДА]\n\n"
            "Режим трусости позволяет вам автоматически выполнять определенную "
            "команду, когда ваши очки здоровья падают ниже заданного процентного"
            "соотношения от максимального количества.  Команда трусости означает, "
            "какая команда будет выполняться при определенном процентном соотношении. "
            "Параметры \"вкл\" and \"выкл\" просто быстро переключают процентное "
            "соотношение в значения 23% и 0% соответственно.  Вы не можете "
            "поставить никакой команды для процентного соотношения больше чем 30%.\n"
            "Если вы поставите команды, например, go и enter:\n"
            "\tgo west\n"
            "режим трусости будет сначала пытаться выполнить эту команду, если это "
            "не получится, она будет искать имеющийся выход у комнаты.  Если "
            "вы установите любую другую команду для трусости, за исключением "
            "go или enter, этот режим не будет пытаться выполнить "
            "никаких других команд.\n"
            "Например, если вы установите следующую команду:\n"
            "\tтрусость портал к мамочке\n"
            "то есть \"портал к мамочке\" это ваша команда трусости, "
            "режим трусости будет пытаться выполнить только эту команду, "
            "даже если ее исполнение закончилось неудачей "
            "(например, если вашей мамочки нет в игре).\n"
            "Команда без параметров просто покажет ваши текущие "
            "настройки.\n"
            "Смотрите также: attack, status");
}

