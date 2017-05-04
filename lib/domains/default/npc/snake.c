#include <position.h>
#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("змея");
    SetId( ({"змея", "рептилия"}) );
    SetAdjectives( ({"маленькая", "безвредная"}) );
    SetShort("змея");
    SetLong("Эта маленькая безвредная рептилия охотится на садовых вредителей и не представляет большой опасности.");
    SetAutoStand(0);
    SetPosition(POSITION_LYING);
    SetLevel(1);
    SetMelee(1);
    SetRace("snake");
    SetGender("male");
}
void init(){
    ::init();
}
