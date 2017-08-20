/*    /cmds/player/converse.c
 *    переведено Tuor
 */

#include <lib.h>
#include <talk_type.h>
#include <commands.h>

inherit LIB_DAEMON;

static void eventChat(string args);

mixed cmd(string args) {
    message("system", "Режим общения.  Вводите текст, который вы хотите "
            "'сказать', пока не закончите.", this_player());
    message("system", "Когда закончите, введите точку '.' в пустой строке.",
            this_player());
    message("system", "______________________________________________________"
            , this_player());
    input_to( (: eventChat :));
    return 1;
}

static void eventChat(string args) {
    if( trim(args) == "." ) {
        message("system", "Выход из режима общения.", this_player());
        return;
    }
    else this_player()->eventSpeak(0, TALK_LOCAL, args);
    input_to( (: eventChat :) );
}

string GetHelp() {
    return ("Синтаксис: общение\n\n"
            "Переводит вас в режим общения, который означает, что все что "
            "вы напишите, будет передано вместе с командой \"говорить\". "
            "Чтобы выйти из режима общения вам нужно, как и в случае с "
            "внутриигровой почтой или доской сообщений, вам нужно просто "
            "отправить одиночную точку '.'.  Также в режиме общения вы можете "
            "использовать игровые команды, поставив перед ними знак '!'.\n"
            "Смотрите также: говорить, сказать");
}
