/* /secure/cmds/player/chfn.c
 *  переведено Tuor
 */

#include <lib.h>

inherit LIB_DAEMON;

mixed cmd(string args) {
    function f;
    string rname;

    message("system", "Изменение общей информации игрока " +
            previous_object()->GetCapName() + ": ", previous_object());
    rname = previous_object()->GetRealName();
    message("prompt", "Настоящее имя [" + rname + "] ", previous_object());
    f = function(string str, string old, object ob) {
        function g;

        if( !str || str == "" ) str = old;
        if( str != old ) {
            ob->SetRealName(str);
            message("system", "Настоящее имя изменено на " + str, ob);
        }
        else message("system", "Настоящее имя не изменено.", ob);
        str = ob->GetEmail();
        message("prompt", "Адрес электронной почты (решетку # могут сделать только админы) ["
                + str + "] ", ob);
        g = function(string str, string old, object ob) {
            function h;

            if( !str || str == "" ) str = old;
            if( str != old ) {
                string a, b;

                if( sscanf(str, "%s@%s", a, b) != 2 ) {
                    message("system", "Неверный адрес электронной почты.", ob);
                    return;
                }
                ob->SetEmail(str);
                message("system", "Адрес электронной почты изменен на " + str, ob);
            }
            else message("system", "Адрес электронной почты не изменен.", ob);
            str = (ob->GetWebPage() || "");
            message("prompt", "Домашняя страница [" + str + "]: ", ob);
            h = function(string str, object who) {
                if( str == "" ) {
                    str = 0;
                }
                else if( str ) {
                    if( strlen(str) < 5 ) {
                        str = "http://" + str;
                    }
                    else {
                        if( str[0..3] != "http" ) {
                            str = "http://" + str;
                        }
                    }
                }
                if( !str ) {
                    message("system", "Домашняя страница не изменена.", who);
                }
                else {
                    who->SetWebPage(str);
                    message("system", "Домашняя страница изменена.", who);
                    this_player()->save_player(this_player()->GetKeyName());
                    update("/secure/daemon/finger");
                }
            };
            input_to(h, 0, ob);
            this_player()->save_player(this_player()->GetKeyName());
            update("/secure/daemon/finger");
        };
        input_to(g, 0, str, ob);
        this_player()->save_player(this_player()->GetKeyName());
        update("/secure/daemon/finger");
    };
    input_to(f, "" + rname, previous_object());
    this_player()->save_player(this_player()->GetKeyName());
    update("/secure/daemon/finger");
    return 1;
}

string GetHelp(){
    return ("Синтаксис: измпрофиль\n\n"
            "Позволяет вам изменить информацию отображаемую в вашем профиле.\n"
            "Смотрите также: passwd, finger, профиль");
}
