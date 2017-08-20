/*  /cmds/players/gag.c
 *   переведено Tuor
 */

#include <lib.h>

inherit LIB_DAEMON;

string ReportSyntax(){
    int admin = adminp(this_player());
    string ret = "Синтаксис: помолчать [remote or local] <вкл или выкл>";
    if(admin) ret += "        помолчать <игрок> [вкл или выкл]";
    return ret;
}

mixed cmd(string str) {
    string which, type;
    object player;
    string *validtypes = ({ "remote", "local", "all" });
    int admin = adminp(this_player());
    if( !sizeof(str) )
        return ReportSyntax();
    str = lower_case(str);
    sscanf(str,"%s %s", type, which);
    if(!which && type){
        which = type;
        type = "all";
    }
    if(!type){
        if(admin){
            player = find_player(str);
        }
        if(!player) which = str;
        else which = "вкл";
        type = "all";
    }
    if(admin){
        if(!player) player = find_player(type);
        if(player){
            if(!which) which = "вкл";
            type = "all";
        }
    }
    if( which != "вкл" && which != "выкл" )
        return "Режим помолчать может быть только 'вкл' или 'выкл'.";
    if( !player && member_array(type, validtypes) == -1 )
        return "Допустимые типы помолчать: remote, local, all.";
    if(!player) player = this_player();
    if(admin){
        player->SetGagged(type, (which == "вкл" ? 2 : 0));
    }
    else {
        player->SetGagged(type, (which == "вкл"));
    }
    message("system",
            "Режим помолчать установлен в "+str+" для "+type+" каналов"+
            (player != this_player() ? " для игрока "+player->GetName() : "")+
            ".", this_player() );
    return 1;
}

string GetHelp() {
    int admin = adminp(this_player());
    return "Синтаксис: помолчать [remote | local] <вкл | выкл>\n"+
        (admin ? "        помолчать <ИГРОК> <вкл | выкл>\n" : "")+
        "\nЭтой командой вы запрещаете себе передавать сообщения по каналам.\n"
        "Полезно когда вы прячитесь или используете несколько персонажей.\n"
        "Вы можете помолчать себя по всем каналам: помолчать вкл\n"
        "See also: mute, env, режим";
}
