/*  /cmds/players/env.c
 *   переведено Tuor
 */

#include <lib.h>

inherit LIB_DAEMON;

string GetMuted(){
    string ret;
    if(this_player()->GetMutedType("local")){
        ret = "local: %^RED%^ЗАГЛУШЕН%^RESET%^";
    }
    else {
        ret = "local: %^GREEN%^прослушивается%^RESET%^";
    }
    if(this_player()->GetMutedType("remote")){
        ret += ", remote: %^RED%^ЗАГЛУШЕН%^RESET%^";
    }
    else {
        ret += ", remote: %^GREEN%^прослушивается%^RESET%^";
    }
    return ret;
}

string GetGagged(){
    string ret;
    if(this_player()->GetGaggedType("local")){
        ret = "local: %^RED%^ЗАГЛУШЕН%^RESET%^";
    }
    else {
        ret = "local: %^GREEN%^прослушивается%^RESET%^";
    }
    if(this_player()->GetGaggedType("remote")){
        ret += ", remote: %^RED%^ЗАГЛУШЕН%^RESET%^";
    }
    else {
        ret += ", remote: %^GREEN%^прослушивается%^RESET%^";
    }
    return ret;
}

mixed cmd(string args) {
    object player = this_player();
    mixed replee = player->GetProperty("reply");
    string ret = "";
    string *tmp;
    ret += "Экран: \t\t"+identify(this_player()->GetScreen())+"\n";
    ret += "Терминал: \t\t"+this_player()->GetTerminal()+"\n";
    ret += "Краткий режим: \t\t"+ ( (this_player()->GetBriefMode()) ? "вкл" : "выкл" )+"\n";
    ret += "Cursefilter: \t\t"+ ( (this_player()->GetParanoia("cursefilter")) ? "вкл" : "выкл" )+"\n";
    ret += "Цветные сообщения каналов: "+ ( (this_player()->GetNoChanColors()) ? "выкл" : "вкл" )+"\n";
    ret += "Режим ПК: \t"+ ( (this_player()->GetPK()) ? "вкл" : "выкл" )+"\n";
    ret += "Режим глухоты: \t\t"+ GetMuted()+" \n";
    ret += "Режим помолчать: \t\t"+ GetGagged()+" \n";
    ret += "Режим трусости: \t\t"+ ( (this_player()->GetWimpy()) ? "вкл" : "выкл" )+"\n";
#if efun_defined(compressedp)
    ret += "Режим MCCP: \t\t"+(compressedp(this_player()) ? "вкл" : "выкл")+"\n";
#endif
#if MINIMAP
    ret += "Режим миникарты: \t\t"+ ( this_player()->GetProperty("minimapping") ? "вкл" : "выкл" )+"\n";
#endif
    ret += "Режим докучблок: \t\t"+ ( (this_player()->GetAnnoyblock()) ? "вкл" : "выкл" )+"\n";
    ret += "Режим репромпт: \t\t"+ ( this_player()->GetProperty("reprompt") ? "вкл" : "выкл" )+"\n";
    ret += "Screenlock mode: \t"+ ( this_player()->GetProperty("screenlock") ? "вкл" : "выкл" )+"\n";
    ret += "Timezone: \t\t"+ ( this_player()->GetProperty("timezone") ? 
            this_player()->GetProperty("timezone") : "None specified" )+"\n";
#ifdef __GET_CHAR_IS_BUFFERED__
    ret += "Charmode: \t\t"+ 
        //( (query_charmode(player) > 0) ? "on" : "off" )+"\n";
        ( (player->GetCharmode()) ? "вкл" : "выкл" )+"\n";
#endif
    ret += "Режим командаотр: \t\t"+ ( this_player()->GetProperty("commandecho") ? this_player()->GetProperty("commandecho") : "off" )+"\n";
#ifdef __DSLIB__
    ret += "Keepalive mode: \t"+ ( this_player()->GetProperty("keepalive") 
            ? this_player()->GetProperty("keepalive") : "off" )+"\n";
#endif

    if(creatorp(this_player())){ 
        ret += "Домашняя директория: \t\t"+user_path(this_player())+"\n";
        if(this_player()->GetParanoia("homeroom")){
            ret += "Стартовая комната: \t\t"+this_player()->GetParanoia("homeroom")+"\n";
        }
        ret += "Debug mode: \t\t"+ ( (this_player()->GetProperty("debug")) ? "вкл" : "выкл" )+"\n";
        ret += "Godmode: \t\t"+ ( (this_player()->GetGodMode()) ? "вкл" : "выкл" )+"\n";
        ret += "Wizvision: \t\t"+ ( (this_player()->GetWizVision()) ? "вкл" : "выкл" )+"\n";
#if GRID
        ret += "Showgrid: \t\t"+ ( (this_player()->GetVisibleGrid()) ? "вкл" : "выкл" )+"\n";
        ret += "Wizmap mode: \t\t"+ ( this_player()->GetProperty("wizmapping") ? "вкл" : "выкл" )+"\n";
        ret += "Noclip mode: \t\t"+ ( this_player()->GetProperty("noclip") ? "вкл" : "выкл" )+"\n";
        ret += "Anchor: \t\t"+ ( this_player()->GetAnchored() ? "вкл" : "выкл" )+"\n";
#endif
    }
    if(replee){
        ret += "Будете отвечать: \t\t"+replee+"\n";
    }
    tmp = sort_array(explode(ret, "\n"),1);
    ret = implode(tmp, "\n");
    write(ret);
    return 1;
}

string GetHelp() {
    string *see_also = ({});
    if(creatorp(this_player())){
        see_also = ({ "debug" , "showgrid",
                "wizvision", "godmode", "wizmap", "noclip" });
    }
    see_also += ({ "brief", "chancolors", "commandecho", "cursefilter",
            "terminal", "screen", "pk", "mute", "gag", "wimpy", "minimap",
            "annoyblock", "reprompt", "charmode", "keepalive", "timezone",
            "screenlock" });
    return ("Синтаксис: режим\n\n"
            "Отображает основные настройки игры и интерфейса.\n" +
            "Смотрите также: "+implode(sort_array(see_also, 1), ", "));
}
