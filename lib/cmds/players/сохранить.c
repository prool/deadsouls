/*  /cmds/players/save.c
 *   переведено Tuor
 */
 
#include <lib.h>

inherit LIB_DAEMON;

int cmd(){
    if(this_player()->query_disable()) {
        write("Подождите минутку.");
        return 1;
    }
    this_player()->set_disable();
    this_player()->save_player(this_player()->GetKeyName());
    write(this_player()->GetName()+" - сохранение успешно.");
    return 1;
}

string GetHelp(){
    return ("Синтаксис: сохранить\n\nЭта команда сохраняет"
            " текущее состояние вашего персонажа на диск. Это может быть полезно"
            " в случаях если MUD подвисает или падает. "
            "Ваш персонаж автоматически сохраняется, "
            "когда вы выходите из игры.");
}
