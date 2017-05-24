#include <lib.h>
#include <daemons.h>
inherit LIB_ROOM;

object ob;
mapping Levels = PLAYERS_D->GetLevelList();
int ReadSign();
int ReadScroll();

static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Гильдия авантюристов");
    SetLong("Это маленькое здание, где искатели приключений могут записывать свои приключения и оставлять сообщения и объявления другим храбрецам. Здесь также можно повысить уровень и если вы заслуживаете, то попросите об этом гильдмастера. Вы видите здесь также список заданий и табличку с инструкциями. На юге расположены Залы билдеров, а вверху тренировочная комната, где вы можете выучить умения. На востоке находится приватная комната, где вы можете обсуждать разные вещи без лишних ушей.");
    SetItems( ([
                ({ "list","список"}) : "Список прикреплен к одной из стен, в нем перечислены "
                "некоторые задания, за выполнение которых вы можете получить "
                "награду.",
                ({"табличка","инструкции"}) : "На этой табличке выбиты "
                "основные инструкции о том, как повысить опыт и "
                "получить повышение.",
                ({"здание","маленькое здание","здесь"}) : "Вы в "
                "Гильдии авантюристов.",
                ]) );
    SetExits( ([
                "north" : "/domains/town/room/vill_road2",
                "south" : "/domains/default/room/builder_hall",
                "east" : "/domains/town/room/confroom",
                "up" : "/domains/town/room/training.c",
                ]) );
    SetInventory(([
                "/domains/town/obj/bin" : 1,
                "/domains/town/obj/table" : 1,
                "/domains/town/npc/dirk" : ({60, 1})
                ]));
    SetRead( ([
                ({"list","список"}) : (: ReadScroll :),
                ({"инструкции","табличка","табличку"}) : (: ReadSign :)
                ]) );

    SetProperty("no attack", 1);
    ob = new(LIB_BOARD);
    ob->SetKeyName("доска объявлений");
    ob->SetId( ({ "доска", "доска объявлений", "пыльная", "пыльная доска" }) );    
    ob->set_board_id("adv_guild_board");
    ob->set_max_posts(30);
    ob->SetShort("пыльная доска объявлений");
    ob->eventMove(this_object());
    SetNoClean(1);
}

mixed ReadSign(){
    int i;
    string ret = read_file("/domains/town/txt/advancement.txt");
    ret += "\n";
    for(i=1;i<21;i++){
        ret +=  sprintf("%:-3s     %:-28s %:-12s %:16s\n", i+"",
                Levels[i]["title"], Levels[i]["xp"]+"", (Levels[i]["qp"] || "none")+"");
    }
    ret += "\nДля повышения попросите гильдмастера.\nНапример:\n\n";
    ret += "ask dirk to advance";
    return this_player()->eventPage(({ret}));
}

mixed ReadScroll(){
    return this_player()->eventPage("/domains/town/txt/quests.txt");
}

void init(){
    ::init();
}
