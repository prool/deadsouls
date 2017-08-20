/*    /cmds/player/who.c
 *    переведено Tuor
 */

#include <lib.h>
#include <privs.h>
#include <daemons.h>

inherit LIB_DAEMON;
mapping instinfo;
mixed instances;

#define SEP repeat_string("*=",39)+"*\n";

static int LevelSort(mixed one, mixed two){
    int i1, i2, alpha;
    string s1, s2;
    if(objectp(one)){
        i1 = one->GetLevel();
        s1 = one->GetName();
        if(creatorp(one)) alpha = 1;
    }
    if(objectp(two)){
        i2 = two->GetLevel();
        s2 = two->GetName();
        if(creatorp(two)) alpha = 1;
    }
    if(stringp(one) && sizeof(instinfo) && mapp(instinfo[one])){
        i1 = instinfo[one]["level"];
        s1 = one;
        if(instinfo[one]["creator"]) alpha = 1;
    }
    if(stringp(two) && sizeof(instinfo) && mapp(instinfo[two])){
        i2 = instinfo[two]["level"];
        s2 = two;
        if(instinfo[two]["creator"]) alpha = 1;
    }
    if(alpha) return strcmp(s1, s2);
    if(i1 > i2) return -1;
    else if(i2 > i1) return 1;
    else if(s1 && s2) return strcmp(s1, s2);
    return -1;
}

int cmd(string args) {
    int p;
    string x, tmp="", ret="";
    object *obs;

    if (args && args[0] == '@') { //If there's an @ in the first arg character, it's an rwho request.
        if( sizeof(args) <=1 ) return notify_fail("Get a remote who from where?"); //If there's only an @, tell them to RTFM.
        "/cmds/players/rwho"->cmd(args[1..]); //Pass it the mud name without the @
        return 1;
    } else {
        mixed arches, cres, players;
        p = 0;
        arches = sort_array(filter(users(), (: archp($1) :)),
                "LevelSort");
        cres = sort_array(filter(users(), (: !archp($1) && creatorp($1):)),
                "LevelSort");
        players = sort_array(filter(users(), (: !creatorp($1) :)),
                "LevelSort");
        obs = arches + cres + players;

        for (int i=0; i<sizeof(users()); i++) {
            string fnm;
            if(!obs[i] || !environment(obs[i])) continue;
            sscanf(last_string_element(base_name(obs[i]), "/"),"%s.%*s", fnm);
            if(fnm && fnm != obs[i]->GetKeyName()) continue;
            if(!obs[i]->GetInvis()){
                if(archp(obs[i])) tmp+="[%^BLUE%^АДМИНИСТРАЦИЯ%^RESET%^]";
                else if(creatorp(obs[i]) ) tmp+="[%^CYAN%^БИЛДЕРЫ%^RESET%^]";
                else if(avatarp(obs[i]) ) tmp+="[%^GREEN%^АВАТАРЫ%^RESET%^]";
                else if(high_mortalp(obs[i]) ){
                    tmp+="[%^GREEN%^ГЕРОИ%^RESET%^]";
                }
                else tmp+=sprintf("[%d]", obs[i]->GetLevel() );
                if(elderp(obs[i])) tmp+="[%^YELLOW%^СОВЕТНИКИ%^RESET%^]";
                if(testp(obs[i]) && !archp(obs[i])){
                    tmp+="[%^B_CYAN%^%^BLACK%^ТЕСТОВЫЕ ПЕРСОНАЖИ%^RESET%^]";
                }
                if(ambassadorp(obs[i])) tmp+="[%^YELLOW%^ПОСЛАННИКИ%^RESET%^]";
                tmp += ": ";
                if(sizeof(strip_colours(obs[i]->GetShort())) < 50) {
                    tmp+=sprintf(" %s", obs[i]->GetShort());
                }
                else {
                    tmp += " " + capitalize(obs[i]->GetKeyName())+ 
                        " Много-титулованный.";
                }
                if(obs[i]->GetSleeping() > 0){
                    tmp += " (%^BLUE%^спит%^RESET%^) ";
                }
                else if (obs[i]->GetProperty("afk")){
                    tmp += " (%^MAGENTA%^афк%^RESET%^)";
                }
                else if (query_idle(obs[i])>240 && obs[i]->GetInCombat()!=1){
                    tmp += " (%^YELLOW%^без связи%^RESET%^)";
                }
                else if (in_edit(obs[i]) || obs[i]->GetCedmode()){
                    tmp += " (%^CYAN%^редактирует%^RESET%^)";
                }
                else if(obs[i]->GetInCombat()){
                    tmp += " (%^RED%^в бою%^RESET%^)";
                }
                tmp += "%^RESET%^\n";
                p++;
            }
        }
        ret+=center(mud_name());
        ret+="\n";
        ret+=SEP;
        ret+=tmp;
        instances = singular_array(INSTANCES_D->GetInstances());
        if(ENABLE_INSTANCES) instances = ({ "global" });
        tmp = INSTANCES_D->GetMyInstanceName();
        if(tmp && instances) instances -= ({ tmp });
        tmp = "";

        foreach(string inst in sort_array(instances, 1)){
            mixed guys;
            mapping tmpmap;
            if(!inst) continue;
            arches = ({});
            cres = ({});
            players = ({});
            guys = ({});
            instinfo = INSTANCES_D->GetInstData()[inst];
            if(!sizeof(instinfo)){
                continue;
            }
            if(instinfo["mudname"]) inst = instinfo["mudname"];
            tmp += "\n"+center("--- Инстанция: "+capitalize(inst)+" ---\n");
            if(!mapp(instinfo["users"])){
                continue;
            }
            foreach(string name, mapping data in instinfo["users"]){
                string tmpname;
                if(name && mapp(data)){
                    tmpname = name;
                    if(data["arch"]) arches += ({ name });
                    else if(data["creator"]) cres += ({ name });
                    else players += ({ name });
                }
            }
            arches = sort_array(arches, "LevelSort");
            cres = sort_array(cres, "LevelSort");
            players = sort_array(players, "LevelSort");
            guys = arches + cres + players;
            foreach(string dude in guys){
                if(!dude) continue;
                tmpmap = instinfo["users"][dude];
                if(!sizeof(tmpmap)) continue;
                if(tmpmap["status"] < 1) continue;
                if(tmpmap["arch"])tmp += "[%^BLUE%^АДМИНИСТРАЦИЯ%^RESET%^]";
                else if(tmpmap["creator"]) tmp += "[%^CYAN%^БИЛДЕРЫ%^RESET%^]";
                else tmp += "["+tmpmap["level"]+"]";
                tmp += ": " + tmpmap["title"];
                if(tmpmap["state"]) tmp += " " +tmpmap["state"];
                tmp += "%^RESET%^\n";
            }
            ret += tmp;
            tmp = "";
        }    
        ret+=SEP;
        x="Здесь ";
        (p==1) ? x+=" " : x+=" ";
        x+=cardinal(p);
        (p==1) ? x+=" член " : x+=" члены ";
        x+="нашего мира.\n";
        ret+=center(x);
        if(check_string_length(ret)) this_player()->eventPrint(""+ret+"");
        else print_long_string(this_player(),ret);
        return 1;
    }
}

string GetHelp(){
    return ("Синтаксис: кто\n\n"
            "Выводит список всех, кто находится сейчас в игре.");
}
