#include <lib.h>
#include <daemons.h>

inherit LIB_DAEMON;

mixed cmd() {
    int *mudtime;
    int hours, minutes;
    string meridiem = " до полудня";
    string nulle = "";
    int daynum = query_date();

    mudtime = SEASONS_D->GetMudTime();
    hours = mudtime[0];
    minutes = mudtime[1];

    // if you want an odd (as in not even) number of hours in
    // a day, this may need fiddling with.

    if(hours >= (DAY_LENGTH / 2))
        meridiem = " после полудня";
    if(hours > (DAY_LENGTH / 2)  && hours != DAY_LENGTH)
        hours -= (DAY_LENGTH / 2);
    if(!hours) hours = (DAY_LENGTH / 2);

    if(minutes < 10) nulle = "0";

    write("Сегодня "+query_day_name()+", "+daynum+" день "+
            query_month()+", "+query_season()+".");

    write("Локальное время: "+hours+":"+nulle+minutes+meridiem+"."); 

    return 1;

}

string GetHelp() {
    return ("Синтаксис: время\n\n"
            "Показывает внутриигровое время. Оно совершенно "
            "не совпадает с реальным временем.");
}
