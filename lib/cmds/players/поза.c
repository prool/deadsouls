/*    /cmds/player/position.c
 *    переведено Tuor
 */

#include <lib.h>
#include <position.h>

inherit LIB_DAEMON;

mixed cmd(string str) {
    int pos;  
    object ob;
    string ret;

    if(str) ob = get_object(str);
    if(!ob || !living(ob)){
        if(str){
            write("Такого существа не найдено.");
            return 1;
        }
        ob = this_player();
        ret = "Ваша поза: ";
    }
    else {
        ret = ob->GetShort()+" ";
    }

    pos = ob->GetPosition();

    switch(pos){
        case POSITION_STANDING : ret += "стоит.";break;
        case POSITION_SITTING : ret += "сидит.";break;
        case POSITION_LYING : ret += "лежит.";break;
        case POSITION_FLYING : ret += "летит.";break;
        case POSITION_KNEELING : ret += "ползет.";break;
        case POSITION_FLOATING : ret += "всплывает.";break;
        case POSITION_SWIMMING : ret += "плывет.";break;
        default : ret += "здесь.";
    }

    write(ret);
    return 1;
}

string GetHelp() {
    return ("Синтаксис: поза [существо]\n\n"
            "Сообщает позу указанного существа или, если никто не указан, "
            "то вашу собственную.");
}
