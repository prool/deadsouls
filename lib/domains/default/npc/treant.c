#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("треант");
    SetAdjectives( ({"древний", "ожившее", "древнее"}) );
    SetId( ({"защитник", "дерево"}) );
    SetShort("древний треант");
    SetLong("Это древний защитник лесов, похожий на ожившее дерево с узловатыми ногами и руками. Обычно они очень доброжелательны, но кто знает, что у этого на уме.");
    SetLevel(1);
    SetMelee(1);
    SetRace("tree");
    SetGender("neuter");
}
void init(){
    ::init();
}
