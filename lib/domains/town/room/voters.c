#include <lib.h>
#include <daemons.h>
#include <voting.h>

inherit LIB_ROOM;

mixed ReadList();

static void create() {
    room::create();
    SetTown("town");
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Избирательная комиссия");
    SetLong("Здесь любой житель города может проголосовать. Также здесь можно 'nominate CANDIDATE'. На стене висит плакат со списком кандидатов. Основная часть города находится на юго-востоке.");
    SetItems( ([ "плакат" : "Плакат со списком кадидатов." ]) );
    SetExits( ([ 
                "southwest" : "/domains/town/room/thall",
                ]) );
    SetRead( "list", (: ReadList :) );
    SetProperties (([
                "no attack":1, 
                "no bump":1, 
                "no steal":0, 
                "no magic":0, 
                "no paralyze":0, 
                "no teleport":0]));
    SetInventory(([
                ]));
}

mixed ReadList() {
    string msg, admin;

    admin = "\nСпециальные команды, доступные дл админов:\n";
    admin += "результаты\t\t\tСообщает о результатах голосования.\n";
    admin += "следующий день\t\t\tУвеличивает голосование на один день.\n";
    admin += "начать голосование\t\tНачинает голосование.\n";
    admin += "закончить голосование\t\t\tЗаканчивает голосование.\n";
    admin += "статус голосования\t\tСообщает статус голосования.\n";
    admin += "режим голосования\t\tСообщает режим голосования.\n\n";

    if(archp(this_player())) this_player()->eventPrint( admin );

    if( VOTING_D->GetStatus() == VOTE_NOT_RUNNING ) {
        this_player()->eventPrint(VOTING_D->GetCurrentCouncil());
        return 1;
    }

    msg = VOTING_D->GetCurrentCouncil();
    msg += "\n\tКандидаты в чиновники AncestryMUD.\n\n";

    foreach( string sClass in CLASSES_D->GetClasses() ) {
        msg += capitalize( sClass ) + " : ";
        foreach( string sName in VOTING_D->GetCandidates(sClass) )
            msg += capitalize(sName) + ", ";
        if( msg[strlen(msg)-2] == ',' )        
            msg = msg[0..strlen(msg)-3];
        msg += "\n";
    }

    this_player()->eventPrint( msg );
    return 1;
}

mixed CanNominate( object who ) { return 1; }
mixed CanVote( object who ) { return 1; }
mixed CanWithdraw( object who ) { return 1; }

mixed eventNominate( object who, string str ) {
    int iErr;

    if( creatorp( who ) ) {
        who->eventPrint("Билдеры не могут голосовать!");
        return 1;
    }

    iErr = VOTING_D->eventAddCandidate( who->GetClass(), str );

    switch( iErr ) {
        case VOTE_NOT_RUNNING :
            this_player()->eventPrint("Сейчас не проходят выборы!");
            break;

        case VOTE_MODE_VOTING :
            this_player()->eventPrint("Время для выдвижения "
                    "кандидатов прошло, голосуйте за выдвинутых.");
            break;

        case VOTE_ERROR :
            this_player()->eventPrint("Произошла какая-то ошибка, вы не можете "
                    "сейчас никого номинировать.");
            break;

        case VOTE_NOT_CLASS_MEMBER :
            this_player()->eventPrint( capitalize(str) + " не является кандидатом "
                    " " + pluralize( who->GetClass() ) + ".");
            break;

        case VOTE_ALREADY_RUNNING :
            this_player()->eventPrint( capitalize(str) + " уже проходит." );
            break;
    }
    return 1;
}

mixed eventVote( object who, string str ) {
    int    iErr;
    string sClass;

    sClass = who->GetClass();
    iErr = VOTING_D->eventCastVote( sClass, who->GetName(), str );

    switch( iErr ) {
        case VOTE_NOT_RUNNING :
            this_player()->eventPrint("Сейчас не проходят выборы!");
            break;

        case VOTE_MODE_CANDIDATES :
            this_player()->eventPrint("Голосование еще не началось. Кандидаты "
                    "все еще выдвигаются. Вы можете выдвинуть своего "
                    "кандидата.");
            break;

        case VOTE_NOT_PRIMARY :
            this_player()->eventPrint("Голосовать может только основной персонаж.");
            break;

        case VOTE_NOT_CLASS_MEMBER :
            this_player()->eventPrint( str + " не является кандидатом "
                    " " + pluralize(who->GetClass()) + ".");
            break;

        case VOTE_ALREADY_VOTED :
            this_player()->eventPrint("Вы уже проголосовали!");
            break;

        case VOTE_SUCCESS :
            this_player()->eventPrint("Вы проголосовали!");
            break;        
    }

    return 1;
}

mixed eventWithdraw( object who ) {
    int iErr;

    iErr = VOTING_D->eventRemoveCandidate( who->GetClass(), who->GetName()
            );

    switch( iErr ) {
        case VOTE_NOT_RUNNING :
            this_player()->eventPrint("Сейчас не проходят выборы!");
            break;

        case VOTE_MODE_VOTING :
            this_player()->eventPrint("Выборы начались, сейчас "
                    "слишком поздно отступать назад.");
            break;

        case VOTE_NOT_CANDIDATE :
            this_player()->eventPrint("Вы не являетесь кандидатом.");
            break;
    }

    return 1;
}

mixed tally(){
    write("Голос из ниоткуда произнес: \"Результаты голосования.\"");
    return VOTING_D->eventTallyVotes();
}
mixed nextday(){
    write("Голос из ниоткуда произнес: \"Голосование продлено на следующий день.\"");
    return VOTING_D->eventNextDay();
}
mixed startvote(){
    return VOTING_D->eventStartVoting();
}
mixed endvote(){
    write("Голос из ниоткуда произнес: \"Голосование окончено.\"");
    return VOTING_D->eventEndVoting();
}
mixed votestatus(){
    write("Голос из ниоткуда произнес: \"Статус голосования.\"");
    return VOTING_D->GetStatus();
}
mixed votemode(){
    write("Голос из ниоткуда произнес: \"Режим голосования.\"");
    return VOTING_D->GetMode();
}

void init(){
    ::init();
    add_action("результаты","tally");
    add_action("следующий день","nextday");
    add_action("начать голосование","startvote");
    add_action("закончить голосование","endvote");
    add_action("статус голосования","votestatus");
    add_action("режим голосования","votemode");
}
