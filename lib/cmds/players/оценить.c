/*    /cmds/player/consider.c
 *    переведено Tuor
 */
 

#include <lib.h>
#include <damage_types.h>

inherit LIB_DAEMON;

int eventConsider(object whom, object opponent){
    int score = 0;
    int tmp = 0;
    int protection = 0;
    string *attack_types = ({});
    object *dam_types = ({});
    object *weapons = filter(all_inventory(whom), (: $1->GetWielded() :));
    object *enemy_armor = filter(all_inventory(opponent), (: $1->GetWorn() :));
    enemy_armor = filter(enemy_armor, (: !($1->GetWielded()) :) );

    if(sizeof(weapons)){
        foreach(object weapon in weapons){
            if(weapon->GetWeaponType() && whom->GetSkill(weapon->GetWeaponType()+" attack")){
                attack_types += ({ weapon->GetWeaponType() });
                score += ( whom->GetSkill(weapon->GetWeaponType()+" attack")["level"] ) * 3;
            }
            if(weapon->GetClass())
                score += ( weapon->GetClass() ) * 6;
            if(weapon->GetHands() > 1) {
                if(!(whom->GetSkill("multi-hand"))) score /= 3;
            }
        }
        if(sizeof(weapons) >1) {
            if(!(whom->GetSkill("multi-weapon"))) score /= 3;
        }
    }

    else if((whom->GetMelee())) {
        if(whom->GetSkill("melee attack"))
            score += (((whom->GetSkill("melee attack")["level"]) * 3)); 
    }
    if(!sizeof(attack_types)) attack_types = ({"blunt"});
    foreach(string Type in attack_types){
        int DamType = 0;
        int tmp_prot = 0;
        object *qual_armor = ({});

        switch(Type){
            case "blade" : DamType = BLADE; break;
            case "blunt" : DamType = BLUNT; break;
            case "knife" : DamType = KNIFE; break;
            case "water" : DamType = WATER; break;
            case "shock" : DamType = SHOCK; break;
            case "cold" : DamType = COLD; break;
            case "heat" : DamType = HEAT; break;
            case "gas" : DamType = GAS; break;
            case "acid" : DamType = ACID; break;
            case "magic" : DamType = MAGIC; break;
            case "poison" : DamType = POISON; break;
            case "disease" : DamType = DISEASE; break;
            case "trauma" : DamType = TRAUMA; break;
            default : DamType = BLUNT; break;
        }

        foreach(object armor in enemy_armor){
            tmp_prot += armor->GetProtection(DamType);
            if(armor->GetProtection(DamType)) qual_armor += ({ armor });
        }
        if(sizeof(qual_armor)) protection += tmp_prot / sizeof(qual_armor);
        tmp_prot = 0;
        DamType = 0;
    }

    score += whom->GetStatLevel("speed") * 2;
    score += whom->GetStatLevel("strength") * 3;
    score += whom->GetMaxHealthPoints() / 15;
    score += protection;

    return score;
}

mixed cmd(string str) {
    object thing;
    int totalscore, myscore, theirscore;

    if(!str){
        write("Оценить кого?");
        return 1;
    }
    if(!(thing = present(str,environment(this_player())))){
        write("Этого здесь нет.");
        return 1;
    }
    if(!living(thing)){
        write("Это не живой противник.");
        return 1;
    }

    theirscore = eventConsider(thing, this_player());
    myscore = eventConsider(this_player(), thing);

    totalscore = myscore - theirscore;
    if(totalscore > 100) write("Как младенца обидеть.");
    else if(totalscore > 80) write("Не составит проблем.");
    else if(totalscore > 60) write("Очень легко.");
    else if(totalscore > 40) write("Относительно легко.");
    else if(totalscore > 20) write("Вы скорее всего победите.");
    else if(totalscore > 0) write("Равный поединок.");
    else if(totalscore > -20) write("Заставит попотеть.");
    else if(totalscore > -40) write("Серьезная схватка.");
    else if(totalscore > -60) write("Трудная битва.");
    else if(totalscore > -80) write("Плохая идея.");
    else if(totalscore > -100) write("Очень плохая идея.");
    else write("Самоубийство.");
    return 1;
}

string GetHelp() {
    return ("Синтаксис: оценить <противник>\n\n"
            "Дает вам подсказку, как трудно будет победить этого противника "
            "в сражении. Сравнивает соотношение силы, умений, оружия, "
            "доспехов, уровней, здоровья и т.п. Результирующая оценка "
            "может быть не очень полезной, т.к. изменение хода битвы (такое как "
            "смена противником оружия или использование специальных магических "
            "предметов) не принимается в "
            "расчет.");
}
