#include <lib.h>
#include <daemons.h>
#include <talk_type.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <armor_types.h>

inherit LIB_ARMOR;
inherit LIB_SHOOT;
inherit LIB_ACTIVATE;
int tracking, debugging, active, cache, maxcache = 100;
mapping Prey = ([]);
object myroom;

varargs mixed DoWear(object who, mixed where);

string LongDesc(){
    string ret = "Высокотехнологическое оружие неземного происхождения, "+
        "которым можно вооружиться.";
    if(!active) return ret;
    if(cache < percent_of(10, maxcache)) ret += " Подсвечен %^RED%^красным%^RESET%^ цветом.";
    else if(cache < percent_of(50, maxcache)) ret += " Подсвечен %^YELLOW%^желтым%^RESET%^ цветом.";
    else if(cache < percent_of(80, maxcache)) ret += " Подсвечен %^GREEN%^зеленым%^RESET%^ цветом.";
    else ret += " Подсвечен %^BLUE%^синим%^RESET%^ цветом.";
    return ret;
}

static void create() {
    ::create();
    SetKeyName("бластер");
    SetId(({"бластер"}));
    AddSave(({"cache","Prey"}));
    SetAdjectives(({"неземной","неземное","высокотехнологическое"}));
    SetShort("плазменный бластер");
    SetLong((:LongDesc:));
    SetMass(400);
    SetDollarCost(15000);
    SetVendorType(VT_WEAPON|VT_ARMOR);
    SetArmorType(A_CUSTOM);
    SetRestrictLimbs(({"torso"}));
    SetWear( (: DoWear :) );
    AddItem( ({"light","status light"}), "Уровень освещения");
    set_heart_beat(2);
    Prey = ([]);
}

varargs int OperateThing(object who, mixed what){
    object env;
    string this;
    if(!who) who = this_player();
    env = environment(this_player());
    this = remove_article(GetShort());
    tell_player(who, "Вы используете "+this+".");
    tell_object(env, who->GetName() + " использует " + possessive(who) +
            " " + this + ".", ({who}));
    if(what && stringp(what) && !active){
        tell_player(who, ""+this+" не активирован.");
        return 0;
    }
    return 1;
}

varargs mixed eventShoot(object who, mixed target, string dir, string whom){
    string name, patsy;
    object bolt, killer, env, room = room_environment();
    int fuel, dam;
    killer = (who || this_player());
    fuel = killer->GetMagicPoints();
    name = killer->GetName();
    env = environment(killer);
    if(target) patsy = target->GetName();

    if(creatorp(who)){
        cache = maxcache;
        fuel = 800;
        who->AddMagicPoints(800);
    }

    dam = cache + random(maxcache);

    if(!active){
        write("Щелкнул затвор бластера.");
        say("Щелкнул затвор бластера "+name+".");
        return 1;
    }

    if(cache < 5){
        cache = 0;
        write("Щелкнул затвор бластера.");
        say("Щелкнул затвор бластера "+name+".");
        if(room) room->eventHearTalk(this_object(),0,TALK_LOCAL,"say",
                "Power cache too low.", "poleepkwa");
        return 1;
    }

    if(fuel < maxcache){
        cache = 0;
        write("Бластер издал резкий жужжащий звук.");
        say("Бластер "+name+" издал резкий жужжащий звук.");
        if(room) room->eventHearTalk(this_object(),0,TALK_LOCAL,"say",
                "Operator essence too low.", "poleepkwa");
        return 1;
    }

    if(dir){
        if(!env){
            write("Нет среды.");
            return 1;
        }
        if(!env->GetExit(dir)){
            write("Вы не можете стрелять в этом направлении.");
            return 1;
        }
        bolt = new("/domains/default/weap/plasma");
        if(!bolt){
            write("Тут кажется какая-то неисправность.");
            return 1;
        }
        write("Вы выстрелили из бластера на "+dir+"!");
        tell_room(env, name+" выстрелил "+possessive(killer)+
                " из бластера на "+dir+"!", ({killer}));

        if(debugging) bolt->SetDebugging(1);
        bolt->SetOwner(who);
        bolt->SetOwnerOb(this_object());
        bolt->SetDamage(dam);
        bolt->eventMove(env);
        bolt->SetArmed(1);
        bolt->eventDeploy(dir);
        killer->AddMagicPoints(-maxcache);
        cache = 0;
        return 1;
    }

    write("Вы подстрелили "+patsy+" из вашего бластера!");
    tell_room(env, name+" подстрелил "+patsy+" своим "+possessive(killer)+
            " бластером!", ({killer, target}));
    target->eventPrint(name+" подстрелил вас "+possessive(killer)+
            " бластером!");

    dam = cache + random(maxcache);
    cache = 0;

    target->eventReceiveDamage(killer, HEAT, dam);
    killer->AddMagicPoints(-maxcache);
    target->AddEnemy(killer);

    if(tracking){
        if(room && (!Prey["ob"] || Prey["ob"] != target)){
            room->eventHearTalk(this_object(),0,TALK_LOCAL,"say",
                    "New prey being tracked.", "poleepkwa");
        }
        Prey = ([ "ob" : target, "name" : patsy, "room" : environment(target),
                "player" : userp(target) ]);
    }

    return 1;
}

int ReportHit(object target){
    object here, room;
    string name;
    int player;
    if(!tracking || !active) return 0;
    //if(!inherits(LIB_MISSILE, previous_object())) return 0;
    here = environment(environment());
    if(Prey["ob"] && target == Prey["ob"]){
        here->eventHearTalk(this_object(),0,TALK_LOCAL,"say",
                "Hit scored on target.", "poleepkwa");
        return 1;
    }
    room = environment(target);
    name = target->GetName();
    player = userp(target);
    Prey = (["ob" : target, "name" : name, "room" : room, "player" : player]); 
    here->eventHearTalk(this_object(),0,TALK_LOCAL,"say",
            "New prey being tracked.", "poleepkwa");
    return 1;
}

void heart_beat(){
    int notify;
    string str;
    object env = environment();
    object room = room_environment();
    if(active && !GetWorn()){
        if(env) tell_room(env, remove_article(GetShort())+
                " пищит и пощелкивает.");
        active = 0;
    }
    else if(active){
        int fuel = env->GetMagicPoints();
        if(!fuel){
            active = 0;
            if(environment(env)){
                tell_room(environment(env), env->GetName()+
                        " бластер пищит и пощелкивает.", ({env}));
                env->eventPrint("Ваш бластер пищит и пощелкивает.");
            }
        }
        else if(cache < maxcache){
            env->AddMagicPoints(-1);
            cache++;
        }
    }
    if(active){
        object tmp;
        object penv, menv;
        if(Prey["name"] && !Prey["ob"]){
            if(Prey["player"] && tmp = find_player(Prey["name"])){
                Prey["ob"] = tmp;
                Prey["room"] = environment(tmp);
                Prey["lost"] = 0;
                if(tracking && room){
                    room->eventHearTalk(this_object(),0,TALK_LOCAL,"say",
                            "Contact with prey re-established.", "poleepkwa");
                }
                return;
            }
            else if(!Prey["player"]) Prey = ([]);
            if(room && !Prey["lost"]){
                if(tracking){
                    room->eventHearTalk(this_object(),0,TALK_LOCAL,"say",
                            "Contact with prey lost.", "poleepkwa");
                }
                Prey["lost"] = 1;
            }
            return;
        }
        penv = room_environment(Prey["ob"]);
        menv = room_environment(this_object());
        if(Prey["ob"] && (!Prey["room"] || penv != Prey["room"])){
            if(room) room->eventHearTalk(this_object(),0,TALK_LOCAL,"say",
                    "Prey on the move.", "poleepkwa");
            Prey["room"] = penv;
            notify = 1;
        }
        if(menv != myroom && Prey["ob"]){
            myroom = menv;
            notify = 1;
        }
        if(tracking && notify && room){
            string mycords = ROOMS_D->GetCoordinates(menv);
            string theircords = ROOMS_D->GetCoordinates(penv);
            int i, j, x1, y1, x2, y2, bearing;
            i = sscanf(mycords, "%d,%d,%*s", x1, y1);
            j = sscanf(theircords, "%d,%d,%*s", x2, y2);
            if(i < 2 || j < 2){
                return; 
            }
            bearing = bearing(x2, y2, x1, y1, 1);
            if(bearing != -1) str = "Prey's bearing currently: "+bearing;
            else str = "Prey is in the immediate environment.";
            room->eventHearTalk(this_object(),0,TALK_LOCAL,"say",
                    str, "poleepkwa");
        }
    }
}

void init(){
    object env = environment();
    ::init();
    if(active && !GetWorn()){
        if(env) tell_room(env, remove_article(GetShort())+
                " пищит и пощелкивает.");
        active = 0;
    }
}

varargs mixed DoWear(object who, mixed where){
    string extra;
    object env = environment(who);
    if(creatorp(who) || who->GetRace() == "poleepkwa"){
        active = 1; 
        if(creatorp(who)) cache = maxcache;
    }
    if(active) extra = " и он пискнул и щелкнул.";
    else extra = ".";
    who->eventPrint("Вы вооружились "+GetShort()+extra);
    if(env) tell_room(env, who->GetName()+" вооружился "+
            GetShort()+extra, ({who}));
    return 1;
}

mixed eventUnequip(object who){
    mixed ret = ::eventUnequip(who);
    object env = environment(who);
    if(ret && active){
        who->eventPrint("Ваш бластер пищит и пощелкивает.");
        if(env) tell_room(env, who->GetName()+" бластер "+
                "пищит и пощелкивает.", ({who}));
        active = 0;
    }
    return ret;
}

int eventTurnOn(mixed str){
    if(!OperateThing(this_player(), str)) return 1;
    if(str && stringp(str)){
        if(str == "debugging" && creatorp(this_player())){
            write("Debugging enabled.");
            debugging = 1;
            return 1;
        }
        else if(str == "tracking"){
            if(tracking){
                write("Tracking already enabled.");
                return 1;
            }
            write("Tracking enabled.");
            tracking = 1;
            return 1;
        }
        else {
            write("The "+remove_article(GetShort())+" has "+
                    "no such feature.");
            return 1;
        }
    }
    if(active){
        write("Бластер уже активирован.");
        return 1;
    }
    if(!(this_object()->GetWorn()) || !this_player() ||
            environment(this_object()) != this_player()){
        write("Вы не вооружены "+remove_article(GetShort())+".");
        return 1;
    }
    write("Вы активировали "+remove_article(GetShort())+".");
    say(this_player()->GetName()+" "+remove_article(GetShort())+
            " пискнул и щелкнул.");
    active = 1;
    return 1;
}

int eventTurnOff(mixed str){
    if(!OperateThing(this_player())) return 1;
    if(str && stringp(str)){
        if(str == "debugging" && creatorp(this_player())){
            write("Debugging disabled.");
            debugging = 0;
            return 1;
        }
        else if(str == "tracking"){
            if(!tracking){
                write("Tracking already disabled.");
                return 1;
            }
            write("Tracking disabled.");
            tracking = 0;
            return 1;
        }
        else {
            write("The "+remove_article(GetShort())+" has "+
                    "no such feature.");
            return 1;
        }
    }
    if(!active){
        write("Бластер уже деактивирован.");
        return 1;
    }
    write("Вы деактивировали "+remove_article(GetShort())+".");
    say(this_player()->GetName()+" "+remove_article(GetShort())+
            " пищит и щелкает.");
    active = 0;
    return 1;
}
