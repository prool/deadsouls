/*    /cmds/players/biography.c
 *    переведено Tuor
 */

#include <lib.h>
#include <clock.h>
#include <daemons.h>
#include <marriage.h>
#include <message_class.h>

inherit LIB_DAEMON;

mixed cmd(string args) {
    class marriage *m;
    mapping *deaths;
    mapping kills;
    string *npcs, *tmp, *col1, *col2, *col3;
    string yrstr;
    int x, cols, birth, i;

    cols = ((int *)this_player()->GetScreen())[0];
    tmp = ({ center("Биография персонажа " + this_player()->GetShort() +
                " " + mud_name(), cols), "" });
    birth = this_player()->GetBirth();
    x = query_year(birth);
    if( x < 0 ) yrstr = (-x) + " BN";
    else yrstr = x + "";
    tmp += ({ sprintf("%:-"+(cols/2)+"s%"+(cols/2)+"s", "Уровень: " +
                this_player()->GetLevel(), "Возраст: " +
                ((time() - birth)/YEAR) + " лет") });
    tmp += ({ "You are " + this_player()->GetMoralityDescription()
            + "." });
    tmp += ({ sprintf("Вы родились %d%s дня %s месяца %s года.",
                query_date(birth), ordinal(query_date(birth)),
                query_month(birth), yrstr) });
    m = (class marriage *)this_player()->GetMarriages();
    if( !sizeof(m) ) tmp += ({ "Вы никогда не женились." });
    else {
        class marriage marr;
        string town;

        marr = m[0];
        if( !marr->DivorceDate ) {
            x = query_year(marr->WeddingDate);
            if( x < 0 ) yrstr = (-x) + " BN";
            else yrstr = x + "";
            town = (marr->Location)->GetTown();
            if( !town || town == "wilderness" ) town = ".";
            else town = " в городе " + town + ".";
            tmp += ({ "ВЫ женились " + marr->Spouse + " " +
                    ordinal(query_date(marr->WeddingDate)) + " " +
                    query_month(marr->WeddingDate) + " " + yrstr + town });
            if( sizeof(m) > 1 ) m = m[1..];
            else m = ({});
        }
        if( i = sizeof(m) ) {
            tmp += ({ "Прошлые женитьбы:" });
            while(i--) {
                string yrstr2;

                marr = m[i];
                x = query_year(marr->WeddingDate);
                if( x < 0 ) yrstr = (-x) + " BN";
                else yrstr = x + "";
                x = query_year(marr->DivorceDate);
                if( x < 0 ) yrstr2 = (-x) + " BN";
                else yrstr2 = x + "";
                town = (marr->Location)->GetTown();
                if( !town || town == "wilderness" ) town = "";
                else town = "в городе " + town;		
                tmp += ({ "Вы женились " + marr->Spouse + " " +
                        query_month(marr->WeddingDate) + " " +
                        query_date(marr->WeddingDate) + ", " + yrstr +
                        town + ", разведены " +
                        query_month(marr->DivorceDate) + " " +
                        query_date(marr->DivorceDate) + ", " + yrstr2 + "."
                        });
            }
        }
    }
    deaths = this_player()->GetDeaths();
    if( !(x = sizeof(deaths)) )
        tmp += ({ "Вы никогда не познавали муки смерти." });
    else {
        mapping *d1, *d2;

        tmp += ({ "", "На вас лежит тень смерти по следующей " +
                consolidate(x, "причине") + ":" });
        if( x == 1 ) {
            d1 = deaths[0..0];
            d2 = ({});
        }
        else {
            d1 = deaths[0..(x-1)];
            d2 = deaths[x..];
        }
        for(i=0; i<x; i++)
            tmp += ({ sprintf("%:-" + (cols/2) + "s%s",
                        (i >= sizeof(d1)) ? "" :
                        d1[i]["enemy"],
                        (i >= sizeof(d2)) ? "" :			
                        d2[i]["enemy"]) });
    }	    
    kills = STATISTICS_D->GetKills(this_player()->GetKeyName());
    npcs = sort_array(keys(kills), 1);
    if( !(x = sizeof(npcs)) )
        tmp += ({ "Вы никогда не причиняли другим боль." });
    else {
        tmp += ({ "","Вы ответственны за следующие смерти:" });
        if( x < 3 ) {
            col1 = npcs[0..0];
            if( x == 2 ) col2 = npcs[1..1];
            else col2 = ({});
            col3 = ({});
        }
        else {
            x = x/3;
            col1 = npcs[0..(x-1)];
            col2 = npcs[x..(x+x-1)];
            col3 = npcs[(2*x)..];
        }
        for(i=0; i<x; i++)
            tmp += ({ sprintf("%:-" + (cols/2) + "s%:-" + (cols/2) + "s%s",
                        (i >= sizeof(col1)) ? "" :			
                        col1[i] + " (" + kills[col1[i]] + ")",
                        (i >= sizeof(col2)) ? "" :			
                        col2[i] + " (" + kills[col2[i]] + ")",
                        (i >= sizeof(col3)) ? "" :
                        col3[i] + " (" + kills[col3[i]] + ")") });
    }
    this_player()->eventPage(tmp, MSG_SYSTEM);
    return 1;
}

string GetHelp(){
    return ("Синтаксис: биография\n\n"
            "Биография дает основную информацию по жизни вашего персонажа "
            "в мире " + mud_name() + ".  Эта информация отражает следующее: "
            "рождение, смерти, женитьбы и "
            "т.п.\n"
            "Смотрите также: score");
}
