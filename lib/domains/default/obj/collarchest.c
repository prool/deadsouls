/*    /domains/Examples/etc/bag.c
 *    from the Nightmare IV LPC Library
 *    a sample bag object
 *    created by Descartes of Borg 950529
 */

#include <lib.h>

inherit LIB_STORAGE;

void create() {
    ::create();
    SetKeyName("ящик");
    SetId(({"ящик"}));
    SetAdjectives(({"медицинский","металлический","нержавеющей","стальной"}));
    SetShort("ящик из нержавеющей стали");
    SetLong("Этот ящик используется для хранения медицинских принадлежностей.");
    SetMass(274);
    SetDollarCost(50);
    SetMaxCarry(500);
    SetPreventPut("Вы не можете положить этого здесь!");
    SetInventory(([
                "/secure/obj/medtric" : 1,
                "/domains/default/armor/collar" : 5,
                ]) );
    SetCanClose(1);
    SetClosed(1);
}
mixed CanGet(object ob) { return "Крышка ящика не открывается.";}
