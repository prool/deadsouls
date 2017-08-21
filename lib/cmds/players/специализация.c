/*  /cmds/players/deviate.c
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
        amt = this_player()->GetCustomDeviations();
        this_player()->eventPrint("У вас осталось " + amt + 
                " очков специализации для улучшения.", MSG_SYSTEM);
        return 1;
    }
    if(args == "активировать"){
        int i = this_player()->GetDeviating();
        if(i){
            write("Вы уже активировали специализацию для себя.");
            return 1;
        }
        i = this_player()->SetDeviating(1);
        if(i) write("Специализация активирована.");
        else write("Специализация не активирована. Попросите админа о помощи.");
        return 1;
    }
    if(!this_player()->GetDeviating()){
        write("Вы не активировали специализацию для себя.");
        write("Попробуйте: help deviate");
        write("И help deviation");
        return 1;
    }
    amt = to_int((tmp = explode(args, " "))[<1]);
    if( sizeof(tmp) == 1 ) return "Специализация какой характеристики в каком количестве?";
    stat = implode(tmp[0..<2], " ");
    tmp = this_player()->eventDeviateStat(stat, amt);
    if( stringp(tmp) ) return tmp;
    if( !tmp ) return "Специализация не удалась.";
    this_player()->eventPrint("Вес характеристики " + stat + " сейчас " + tmp +
            "и у вас осталось " +
            this_player()->GetCustomDeviations() +
            " очков специализации.", MSG_SYSTEM);
    return 1;
}

string GetHelp(){
    return ("Синтаксис: специализация\n"
            "        специализация активировать\n"
            "        специализация ХАРАКТЕРИСТИКА КОЛИЧЕСТВО\n\n"
            "Изменяет вес выбранной характеристики, это означает, "
            "она будет улучшаться чаше при получении вашим персонажем "
            "новых уровней. Однако это достигается большим пенальти "
            "при наборе опыта. Вы не можете ни отменить специализацию, "
            "ни ее пенальти. Перед продолжением прочитайте "
            "справку для специализации:\nhelp deviation\n\n"
            "Если вы решили выбрать специализацию, то сначала ее активируйте набрав:\n"
            "специализация активировать\nСмотрите также: deviation, customize, "
            "stat, stats, score, улучшить");
}
