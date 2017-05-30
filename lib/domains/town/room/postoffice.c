#include <lib.h>
#include <objects.h>
#include <post.h>
#include "/lib/include/post_office.h"

inherit LIB_ROOM;

static void create(){
    room::create();
    SetTown("Town");
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Почтовое отделение");
    SetLong("Вы зашли в небольшой офис с рядами почтовых ящиков и других почтовых принадлежностей. "+
            "На стенде за прилавком висит табличка с инструкцией, как отправлять сообщения другим игрокам. "+
            "Единственный выход на востоке ведет к дороге к крепости.");
    SetItems( ([ 
                ({"ящик","ящики","почтовый ящик","почтовые ящики"}) : "Вы видите ряды почтовых ящиков "+
                "расставленных по алфавиту.",
                "табличка" : "На этой табличке объяснено, как отправить сообщение другому игроку.",
                ({"стена","стены"}) : "Стены здесь выкрашены скучной серой краской, "+
                "что, впрочем, не удивительно.",
                "принадлежности" : "Чернила, бумаги и так далее.",
                "инструкции" : "Попытайтесь прочитать их.",
                "счетчик" : "Счетчик ставится автоматически при создании письма." ]) );
    SetExits( ([
                "east" : "/domains/town/room/mountain_road.c",
                ]) );
    SetProperty("no attack", 1);
}
void init(){
    ::init();
    add_action("instr","читать");
}
int instr(string str){
    if(str=="инструкцию"||str=="табличку"){
        write("Чтобы написать кому-нибудь, наберите mail <имя персонажа>.\n"+
                "Введите тему сообщения.\n"+
                "Наберите ваше сообщение.\n"+
                "Когда закончите, введите точку (.) в новой строчке.\n"+
                "Наберите x, затем s чтобы отправить его. Задача выполнена!\n");
        return 1;
    }
}
mixed CanMail(object who, string args) {
    if( !interactive(who) ) return 0;
    if( GetTown() != who->GetTown() )
        return "Любая полученная вами почта будет в вашем домашнем почтовом отделении.";
    return 1;
}
mixed eventMail(object who, string args) {
    object ob;

    if( !(ob = new(OBJ_POST)) ) {
        who->eventPrint("Не удалось найти объект назначения!");
        return 1;
    }
    if( !(ob->eventMove(who)) ) {
        who->eventPrint("Вы кажется не можете нести письмо.");
        return 1;
    }
    ob->start_post(args);
    return 1;
}
int CanReceive(object ob) {
    if( !ob && !(ob = previous_object()) ) return 0;
    if( living(ob) && !interactive(ob) ) return 0;
    else return room::CanReceive(ob);
}
int eventReleaseObject() {
    object ob;

    if( !(ob = previous_object()) ) return room::eventReleaseObject();
    if( !room::eventReleaseObject() ) return 0;
    if( (ob = present(POSTAL_ID, ob)) ) ob->eventDestruct();
    return 1;
}
