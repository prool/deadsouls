/*  /cmds/players/idle.c
 *   переведено Tuor
 */

mixed cmd(string args) {
    int x;
    object who;

    if( !sizeof(args) ) return 1;
    args = convert_name(args);
    who = find_player(args);
    if( !who || who->GetInvis() )
        return "Не удалось никого обнаружить с таким именем.";
    if( !interactive(who) )
        return who->GetName() + " связь оборвалась.";
    x = query_idle(who);
    if( x > 4 ) {
        this_player()->eventPrint(who->GetName()+" был без связи "+time_elapsed(x)+".");
    }
    else this_player()->eventPrint(who->GetName() + " не "
            "терял связь.");
    return 1;
}

string GetHelp(string str) {
    return "Синтаксис: безсвязи [игрок]\n\n"
        "Отображает сколько указанный игрок находится без связи.  Время без связи "
        "отсчитывается с того момента, как игрок последний раз отправлял команду "
        "в MUD.\nЕсли команда введена без аргументов, то она просто не делает "
        "ничего. Это позволяет вам отправлять команды в MUD, чтобы поддерживать "
        "вашу связь не создавая активность в игре.\n"
        "Смотрите также: keepalive, env, режим";
}
