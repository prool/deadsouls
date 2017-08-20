/*    /cmds/player/annoyblock.c
 *    переведено Tuor
 */

#include <lib.h>

inherit LIB_DAEMON;

varargs int cmd(string str){
    if(!str){
        write("Режим докучблок "+ (this_player()->GetAnnoyblock() ? "вкл." : "выкл."));
        return 1;
    }
    if(str == "вкл"){
        if(this_player()->GetAnnoyblock()){
            write("Ваш режим докучблок уже включен.\n");
            return 1;
        }
        this_player()->SetAnnoyblock(1);
        if(this_player()->GetAnnoyblock()){
            write("Вы включили режим докучблок.");
        }
        else {
            write("Ошибка. Режим докучблок не включен.");
        }
        return 1;
    }
    if(str == "выкл"){
        if(!(this_player()->GetAnnoyblock())){
            write("Ваш режим докучблок уже выключен.\n");
            return 1;
        }
        this_player()->SetAnnoyblock(0);
        if(!(this_player()->GetAnnoyblock())){
            write("Вы выключили режим докучблок.");
        }
        else {
            write("Ошибка. Режим докучблок не выключен.");
        }
        return 1;
    }
    write("Попробуйте: help докучблок");
    return 1;
}

string GetHelp(){
    return ("Синтаксис: докучблок [ вкл | выкл ]\n\n"
            "Блокирует докучливые сообщения типа \"Миша посмотрел по сторонам.\""); 
}
