#include <lib.h>
#include <props.h>

inherit LIB_BED;
inherit LIB_SMELL;

static void create() {
    ::create();
    SetKeyName("потрепанная кушетка");
    SetId( ({ "кушетка","софа","диван" }) );
    SetAdjectives( ({ "потрепанная","старая","грязная" }) );
    SetShort("старая потрепанная кушетка");
    SetLong("Это потрепанная, изношенная и грязная кушетка, которую "
            "можно было бы найти только в университетском общежитии.");
    SetMass(3000);
    SetBaseCost("silver",15);
    SetMaxSitters(2);
    SetMaxLiers(1);

    SetSmell( ([
                "default" : "Пахнет неприятно. Кажется, "
                "это собачья моча."
                ]) );
}
