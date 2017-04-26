//     /secure/cmds/players/reply.c
//     from the Dead Souls mudlib
//     replies to the person who previously told to you
//     created by Descartes of Borg 06 february 1993

#include <lib.h>
#include <commands.h>
#include <talk_type.h>
#include <daemons.h>

inherit LIB_DAEMON;

int cmd(string str) {
    string reply,a,b,msg,machine_message,frm;
    object ob, machine;
    mixed err;

    reply = this_player()->GetProperty("reply");
    if(!reply) reply = "никто";
    if(!str) {
        notify_fail("нынешний адресат ответа: "+capitalize(reply)+"\n");
        return 0;
    }
    if(reply == "никто") {
        notify_fail("Некому отвечать.\n");
        return 0;
    }
    this_player()->SetProperty("reply_time", time());
    load_object(CMD_TELL)->cmd(reply+" "+str);
    return 1;
}

string GetHelp(){
    return ("Синтаксис: ответить [сообщение]\n\n"
            "С сообщением вы ответите последнему говорившему с вами. "
            "Без сообщения, команда показывает кому вы ответите. "
            "\nСмотрите также: "
            "finger, idle, muds, say, shout, tell, yell");
}
