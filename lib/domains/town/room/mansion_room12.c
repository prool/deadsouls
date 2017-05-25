#include <lib.h>
inherit LIB_ROOM;

int CheckQuest(object ob);
static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Секретная комната");
    SetLong("Вы находитесь в секретной подземной палате под "
            "особняком.");
    SetExits( ([
                "up" : "/domains/town/room/mansion_room9"
                ]) );
    SetObviousExits("up");
    SetInventory( ([
                "/domains/town/obj/chest2" : 1,
                ]) );
    SetDoor("up", "/domains/town/doors/trapdoor");
}
void init(){
    ::init();
    CheckQuest(this_player());
}
int CheckQuest(object ob){
    string *quests;
    quests = ob->GetQuests();
    if(!ob->GetQuest("Простое задание в секретной комнате")){
        ob->AddQuest("Поиск скрытых комнат","Простое задание в секретной комнате");
        write("%^BOLD%^%^RED%^\n\nПОЗДРАВЛЕНИЯ!\n%^RESET%^");
        write("%^BOLD%^%^RED%^Вы разгадали секретный квест в "+
                "секретной комнате. Вы получили "+
                "2 quest points и 1500 очков опыта. "+
                "Отличная работа!\n\n%^RESET%^");
        say(this_player()->GetName()+" разгадал секретное задание 1.");
        ob->AddQuestPoints(2);
        ob->AddExperiencePoints(1500);
        return 1;
    }
    return 1;
}
