/*  /cmds/players/languages.c
 *   переведено Tuor
 */

#include <lib.h>
#include <talk_type.h>

inherit LIB_DAEMON;

mixed cmd(string str) {
    mapping FluencyMap = ([]);
    string *langs = this_player()->GetLanguages();

    if(str){
        mixed ret = this_player()->CanSpeak(0, TALK_LOCAL, "foo", str);
        if(intp(ret)) {
            this_player()->SetDefaultLanguage(str);
            write("Сейчас вы разговариваете на языке "+capitalize(lower_case(str))+".");
            return 1;
        }
        else return ret;
    }

    foreach(string lang in langs){
        FluencyMap[lang] = this_player()->GetLanguageLevel(lang);
    }

    if(this_player()->GetPolyglot()){
        write("Вы знаете все языки на 100%.");
    }

    write("Вы знаете язык: ");
    foreach(string key, int val in FluencyMap){
        write(capitalize(key)+" на "+val+"%.");
    }
    write("Ваш текущий основной язык: "+
            this_player()->GetDefaultLanguage()+".");

    return 1;
}

string GetHelp() {
    return ("Синтаксис: языки [ЯЗЫК]\n\n"
            "Эта команда сообщает вам, какие языки вы знаете и насколько их понимаете.\n"
            "Если в качестве параметра указан знакомый вам язык, то он "
            "становится вашим основным языком.\n"
            "Смотрите также: languages, speak");
}

