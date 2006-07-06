/*    /domains/Examples/etc/door.c
 *    from the Nightmare IV LPC Library
 *    an example door object connecting doorroom1.c and doorroom2.c
 *    created by Descartes of Borg 950411
 */

#include <lib.h>

inherit LIB_DOOR;


static void create() {
    door::create();
    SetSide("green room", ([ "id" : ({"green door"}),
	"short" : "a green door",
	"long" : "This is a green door.",
	"lockable" : 1 ]) );
    SetSide("east", ([ "id" : ({"green door","door"}),
	"short" : "a green door",
	"long" : "This is a green door.",
	"lockable" : 1 ]) );
    SetClosed(1);
    SetLocked(1);
}
void init(){
    ::init();
}