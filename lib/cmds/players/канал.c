/*  /cmds/player/chan.c
 *   переведено Tuor
 */

#include <daemons.h>

mixed cmd(string args) {
    object ob = this_player();
    int i, cre = creatorp(ob);
    string *channels;
    string command, channel;
    if(!args) return "Попробуйте: help канал";
    i = sscanf(args, "%s %s", command, channel);
    if(!channel) return "Попробуйте: help канал";
    channels = distinct_array(ob->GetChannels());
    if(command == "блокировать"){
        if(member_array(channel, channels) == -1){
            write("Вы не подписаны на этот канал.");
            return 1;
        }
        if(ob->GetBlocked(channel)){
            write(channel + " уже заблокирован.");
        }
        else ob->SetBlocked(channel, 1);
        return 1;
    } 
    if(command == "разблокировать"){
        if(member_array(channel, channels) == -1){
            write("Вы не подписаны на этот канал.");
            return 1;
        }
        if(!ob->GetBlocked(channel)){
            write(channel + " уже разблокирован.");
        }
        else ob->SetBlocked(channel, 0);
        return 1;
    }
    if(!cre){
        write("Попробуйте: help канал");
        return 1;
    }
    if(command == "добавить"){
        if(!creatorp(this_player())){
            write("Попробуйте: help канал");
            return 1;
        }
        if(channel == "все"){
            string *allchans = CHAT_D->GetChannels();
            allchans += CHAT_D->GetRemoteChannels();
            foreach(string chan in allchans){
                //tc("chan: "+identify(chan));
            }
            allchans = sort_array(singular_array(allchans), 1);
            allchans -= ({ "muds" });
            foreach(string chan in allchans){
                string lchan;
                if(sscanf(chan,"%*s:%s",lchan) != 2) lchan = chan;
                if(!ob->GetChannel(lchan)){
                    ob->AddChannel(lchan);
                    if(ob->GetChannel(lchan)){
                        write("Добавлен: "+lchan);
                    }
                }
            }
            write("Выполнено.");
            return 1;
        }
        if(member_array(channel, channels) != -1){
            write("Вы уже подписаны на этот канал.");
            return 1;
        }
        ob->AddChannel(channel);
        channels = distinct_array(ob->GetChannels());
        if(member_array(channel, channels) == -1){
            write("Вы не смогли добавить этот канал себе.");
        }
        else {
            write("Вы добавили канал "+channel+" себе.");
        }
        return 1;
    }
    if(command == "удалить"){
        if(!creatorp(this_player())){
            write("Попробуйте: help канал");
            return 1;
        }
        if(channel == "все"){
            string *allchans = ob->GetChannels();
            foreach(string chan in allchans){
                ob->RemoveChannel(chan);
                if(!(ob->GetChannel(chan))){
                    write("Удален: "+chan);
                }
            }
            write("Выполнено.");
            return 1;
        }
        if(member_array(channel, channels) == -1){
            write("Вы уже не подписаны на этот канал.");
            return 1;
        }
        ob->RemoveChannel(channel);
        channels = distinct_array(ob->GetChannels());
        if(member_array(channel, channels) != -1){
            write("Вы не смогли удалить этот канал у себя.");
        }
        else {
            write("Вы удалили канал "+channel+" у себя.");
        }
        return 1;
    }
    write("Попробуйте: help канал");
    return 1;
}

string GetHelp(){
    int cre = creatorp(this_player());
    string ret = "Синтаксис: канал блокировать <канал>\n";
    ret += "        канал разблокировать <канал>\n";
    if(cre){
        ret += "        канал добавить <канал>\n";
        ret += "        канал удалить <канал>\n";
    }
    ret += "\n";
    ret += "Отображает или модифицирует политику игрока в области "+
        "доступных каналов.";
    ret += "\nСмотрите также: lines, gag, earmuff, env, hist, channels";
    return ret;
}
