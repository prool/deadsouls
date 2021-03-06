#include <lib.h>
#include <daemons.h>
#include <message_class.h>
#include <vision.h>
#include <medium.h>
#include <position.h>

private static mixed globaltmp, tmp;
private static string desc, smell, sound, touch;
private static int i, maxi;

void eventDescribeEnvironment(int brief){
    object env, transport;
    string *shorts;
    string altern_obvious = "";

/* write("prool debug lbl #1"); */

    if(!(env = environment(this_object()))){
        this_object()->eventPrint("Вы находитесь нигде.", MSG_ROOMDESC);
        return;
    }

    if(env->GetMount() || base_name(env) == LIB_CORPSE){ 
        env = environment(environment(this_player()));
        if(!env){
            this_object()->eventPrint("У тебя серьезные проблемы, чувак. Звони Доктору.");
            return;
        }
        i = this_object()->GetEffectiveVision(env); 
    }

    else i =  this_object()->GetEffectiveVision();
    switch( i ){
        case VISION_BLIND:
            this_object()->eventPrint("Вы слепы и ничего не видите.");
            break;
        case VISION_TOO_DARK:
            this_object()->eventPrint("Тут слишком темно.");
            break;
        case VISION_DARK:
            this_object()->eventPrint("Тут темно.");
            break;
        case VISION_TOO_BRIGHT:
            this_object()->eventPrint("Тут слишком ярко, чтобы что-то разглядеть: глаза слепит.");
            break;
        case VISION_BRIGHT:
            this_object()->eventPrint("Тут слишком ярко, чтобы что-то разглядеть.");
            break;
    }
    if( !brief ){
        if( i == VISION_CLEAR ){
    	    /*write("prool debug lbl #2"); */
            desc = env->GetObviousExits() || "";
            if(desc && desc != "" && !(env->GetNoObviousExits()))
                desc = capitalize(env->GetShort() || "")
                    + " [" + desc + "]\n";
            else desc = capitalize(env->GetShort()+"\n" || "\n");
            if(!NM_STYLE_EXITS){
                desc = capitalize(env->GetShort()+"\n" || "\n");
                if(!(env->GetNoObviousExits())){
                    altern_obvious = "Выходы: "+env->GetObviousExits() || "нет"; //$Q - окончание числа (единственного или множественного)
                }
            }
        /* write("prool debug lbl #3"); */
        }
        else desc = "\n";
        if( i == VISION_CLEAR || i == VISION_LIGHT || i == VISION_DIM ){
#if MINIMAP
            if(this_object()->GetProperty("minimapping")){ 
                desc += simple_map(env)+"\n"; 
            }
#endif
#if (WIZMAP && GRID)
            if(MASTER_D->GetPerfOK() && 
                    this_object()->GetProperty("wizmapping")){ 
                desc += MAP_D->GetMap(environment(this_object()),6)+"\n"; 
            }
#endif
            desc += env->GetLong();
            /*write("prooldebug lbl #4"); */
        }
        if(functionp(tmp = env->GetSmell("default")))
            tmp = (*tmp)("default");
        smell = tmp;
        if(functionp(tmp = env->GetListen("default")))
            tmp = (*tmp)("default");
        sound = tmp;
        if( functionp(tmp = env->GetTouch("default")) )
            tmp = evaluate(tmp, "default");
        touch = tmp;
    }
    else {
        if(i == VISION_CLEAR || i == VISION_LIGHT || i == VISION_DIM){
            desc = env->GetShort();
            if(this_object()->GetProperty("minimapping")) desc += simple_map(env)+"\n";
            if(NM_STYLE_EXITS){
                if( (tmp = env->GetObviousExits()) && tmp != "" )
                    desc += " [" + tmp + "]";
                else desc += "\n";
            }
            else altern_obvious = "Выходы: "+env->GetObviousExits() || "нет";
        }
        else desc = "\n";
    }
    if( desc ) this_object()->eventPrint(desc, MSG_ROOMDESC);
    if(sizeof(altern_obvious)){
        int quant = sizeof(env->GetExits()) + sizeof(env->GetEnters());
        if(quant > 1) altern_obvious = replace_string(altern_obvious,"$Q",""); // prool: я удалил s из последней строки
        else altern_obvious = replace_string(altern_obvious,"$Q","");
        this_object()->eventPrint(altern_obvious,MSG_ROOMDESC);
    }
    if( smell ) this_object()->eventPrint("%^GREEN%^" + smell, MSG_ROOMDESC);
    if( sound ) this_object()->eventPrint("%^CYAN%^" + sound, MSG_ROOMDESC);
    if( touch ) this_object()->eventPrint("%^YELLOW%^" + touch, MSG_ROOMDESC);
    desc = "";
    if( i == VISION_CLEAR ){
        mapping lying = ([]);
        shorts = map(filter(all_inventory(env),
                    function(object ob){
                    if( living(ob) ) return 0;
                    if( ob->GetInvis(this_object()) && !ob->GetDoor() )
                    return 0;
                    if(ob->GetDoor() && load_object(ob->GetDoor())->GetHiddenDoor()) return 0;
                    if( ob->isFreshCorpse() ) return 0;
			/*write ("[===]");*/ /* prool */
                    return 1;
                    }), (: $1->GetShort() :));
        foreach(string s in shorts){
            if( s ){
		/* write(s); */ /* prool */
                lying[s]++;
            }
        }
        for(i=0, desc = 0, maxi = sizeof(shorts = keys(lying)); i<maxi; i++){
            string key = replace_string(shorts[i],"%^RESET%^",
                    "%^RESET%^MAGENTA%^");
            int val = lying[shorts[i]];

		/*write(shorts[i]);*/ /* prool */

            if( val < 2 ){
                if( !desc ) desc = "%^MAGENTA%^" +
                    capitalize(key) + "%^RESET%^MAGENTA%^";
                else desc += key + "%^RESET%^MAGENTA%^";
            }
            else {
                if( !desc ) desc = "%^MAGENTA%^" +
                    capitalize(consolidate(val, key)) +
                        "%^RESET%^MAGENTA%^";
                else desc += consolidate(val, key) +
                    "%^RESET%^MAGENTA%^";
            }
            if( i == maxi - 1 ){
                if( maxi > 1 || val >1 )
                    desc += " лежат здесь.%^RESET%^\n";
                else desc += " лежит здесь.%^RESET%^\n";
            }
            else if( i == maxi - 2 ){
                if( maxi == 2 ){
                    desc += " и ";
                }
                else {
                    desc += ", и ";
                }
            }
            else desc += ", ";
        } /* end for */
    }
    i = this_object()->GetEffectiveVision(env);
    if( i == VISION_CLEAR || i == VISION_LIGHT || i == VISION_DIM ){
        mapping lying = ([]), sitting = ([]), standing = ([]), flying = ([]);
        mapping floating = ([]), kneeling = ([]), swimming = ([]);
        mapping furniture = ([]), null = ([]);
        object mount;
        object *obs;
        string key;
        int val;
        if(this_player()) mount = this_player()->GetProperty("mount");

        obs = filter(all_inventory(env), function(object ob){
                if( ob->GetInvis(this_object()) &&
                    !this_object()->GetWizVision() ) return 0;
                if( living(ob) ) return 1;
                if( ob->isFreshCorpse() )
                return 1;
                }) - ({ this_object(), mount });
        maxi = sizeof(shorts = map(obs, (: 
                        ($1->GetInvis() ? "(invisible) " : "") + 
                        $1->GetHealthShort() :)));
        foreach(object liv in obs){
            int envtype = environment(liv)->GetMedium();
            string s = liv->GetHealthShort();
            int pos = liv->GetPosition();
            if( !s ) continue;
            if(liv->GetInvis() && this_object()->GetWizVision()){
                s = "(invis) " + s;
            }
            if(liv->GetProperty("furniture")){
                s += "BEGIN"+random(999999)+"END";
            }
            if(liv->GetProperty("furniture")){ 
                furniture[s] = liv->GetProperty("furniture");
            }
            else if(!furniture[s]) furniture[s] = 0;

            if( pos == POSITION_STANDING) standing[s]++;
            else if( pos == POSITION_LYING || 
                    (liv->isFreshCorpse() && envtype == MEDIUM_LAND) )
                lying[s]++;
            else if( pos == POSITION_SITTING ) sitting[s]++;
            else if( pos == POSITION_FLYING ) flying[s]++;
            else if( pos == POSITION_FLOATING ||
                    (liv->isFreshCorpse() && envtype != MEDIUM_LAND) )
                floating[s]++;
            else if( pos == POSITION_SWIMMING ) swimming[s]++;
            else if( pos == POSITION_KNEELING ) kneeling[s]++;
            else if( pos == POSITION_NULL ) null[s]++;
            else lying[s]++;
        }
        if( !desc ){
            tmp = "";
        }
        else {
            tmp = desc;
        }
        desc = "";
        foreach(key, val in lying){
            globaltmp = key;
            if(grepp(key,"BEGIN")){
                sscanf(key,"%sBEGIN%*s",key);
            }

            if(lying[globaltmp]>1 && !furniture[globaltmp]){
                desc += capitalize(consolidate(val, globaltmp)) +
                    "%^RESET%^ are lying down.";
            }
            else if(lying[globaltmp]<2 && !furniture[globaltmp]){
                desc += capitalize(key) + "%^RESET%^ is lying down.";
            }
            else if(furniture[globaltmp]){
                desc += capitalize(key) + "%^RESET%^ is lying down"+
                    ((furniture[globaltmp]) ? furniture[globaltmp] : "") +".";
            }
            else if(furniture[key]){
                desc += capitalize(key) + "%^RESET%^ is lying down"+
                    ((furniture[key]) ? furniture[key] : "") +".";
            }


            else {
                desc += "wtf. i am "+key+", furniture["+globaltmp+"] is: "+furniture[globaltmp]+"\n"+
                    "  furniture["+key+"] is: "+furniture[key]+", and val is: "+val;
            }

            desc += "\n";
        }
        foreach(key, val in sitting){
            globaltmp = key;
            if(grepp(key,"BEGIN")){
                sscanf(key,"%sBEGIN%*s",key);
            }

            if(sitting[globaltmp]>1 && !furniture[globaltmp]){
                desc += capitalize(consolidate(val, globaltmp)) +
                    "%^RESET%^ are sitting down.";
            }
            else if(sitting[globaltmp]<2 && !furniture[globaltmp]){
                desc += capitalize(key) + "%^RESET%^ is sitting down.";
            }
            else if(furniture[globaltmp]){
                desc += capitalize(key) + "%^RESET%^ is sitting down"+
                    ((furniture[globaltmp]) ? furniture[globaltmp] : "") +".";
            }
            else if(furniture[key]){
                desc += capitalize(key) + "%^RESET%^ is sitting down"+
                    ((furniture[key]) ? furniture[key] : "") +".";
            }


            else {
                desc += "wtf. i am "+key+", furniture["+globaltmp+"] is: "+furniture[globaltmp]+"\n"+
                    "  furniture["+key+"] is: "+furniture[key]+", and val is: "+val;
            }
            desc += "\n";
        }
        foreach(key, val in standing){
            if(grepp(key,"BEGIN")){
                sscanf(key,"%sBEGIN%*s",key);
            }
            if( val<2 )
                desc += capitalize(key) + "%^RESET%^ стоит здесь.";
            else desc += capitalize(consolidate(val, key)) +
                "%^RESET%^ стоят здесь.";
            desc += "\n";
        }
        foreach(key, val in flying){
            if( val<2 )
                desc += capitalize(key) + "%^RESET%^ летает здесь.";
            else desc += capitalize(consolidate(val, key)) +
                "%^RESET%^ летают здесь.";
            desc += "\n";
        }
        foreach(key, val in floating){
            if( val<2 )
                desc += capitalize(key) + "%^RESET%^ плавает здесь.";
            else desc += capitalize(consolidate(val, key)) +
                "%^RESET%^ плавают здесь.";
            desc += "\n";
        }
        foreach(key, val in swimming){
            if( val<2 )
                desc += capitalize(key) + "%^RESET%^ плывет здесь.";
            else desc += capitalize(consolidate(val, key)) +
                "%^RESET%^ плывут здесь.";
            desc += "\n";
        }
        foreach(key, val in kneeling){
            if( val<2 )
                desc += capitalize(key) + "%^RESET%^ сидит на корточках здесь.";
            else desc += capitalize(consolidate(val, key)) +
                "%^RESET%^ сидят на корточках здесь.";
            desc += "\n";
        }
        foreach(key, val in null){
            if( val<2 )
                desc += capitalize(key) + "%^RESET%^ находится здесь.";
            else desc += capitalize(consolidate(val, key)) +
                "%^RESET%^ находятся здесь.";
            desc += "\n";
        }
    }
    if( tmp ){
        desc = tmp + desc;
    }
    if(this_player() && transport = this_player()->GetProperty("mount")){
        string mount_inv = "Nothing";
        string *mount_stuffs = ({});
        object *mount_obs = filter( all_inventory(transport),
                (: ( (($1->GetInvis()) && this_object()->GetWizVision() )
                     || !($1->GetInvis()) ) 
                 && !($1 == this_player()) :));
        if(sizeof(mount_obs)){
            foreach(object element in mount_obs){
                string invis = (element->GetInvis() ? "(invisible) " : "");
                mount_stuffs += ({ invis+element->GetShort() });
            }
            mount_inv = conjunction(mount_stuffs);
        }
        if(!sizeof(desc)) desc = "";
        if(inherits(LIB_CHAMBER,transport)){
            string tmpdesc = transport->GetVehicleInterior();
            if(!tmpdesc || !sizeof(tmpdesc)){ 
                desc += "\nYou are in "+
                    transport->GetPlainShort()+".";
            }
            else desc += "\n"+tmpdesc;
            desc += "\nHere you see: "+mount_inv+".";
        }
        else if(inherits(LIB_VEHICLE,transport)){
            string tmpdesc = transport->GetVehicleInterior();
            if(!tmpdesc || !sizeof(tmpdesc)){
                desc += "\nYou are riding in "+
                    transport->GetPlainShort()+".";
            }
            else desc += "\n"+tmpdesc;
            desc += "\nHere you see: "+mount_inv+".";
        }
        else {
            desc += "\nYou are riding on "+
                transport->GetPlainShort()+".";
            desc += "\nOn "+transport->GetPlainShort()+
                " you see: "+mount_inv+".";
        }
    }
    if( sizeof(desc) ){
        if(check_string_length(desc)) this_object()->eventPrint(desc + "\n", MSG_ROOMDESC);
        else print_long_string(this_player(), desc);
    }
}
