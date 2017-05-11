#include <lib.h>
#include <dirs.h>
#include ROOMS_H
#include <virtual.h>
#include <position.h>

inherit LIB_VIRT_LAND;

varargs static void create(int x, int y) {
    SetNoReplace(1);
    virt_land::create();
    SetClimate("temperate");
    SetAmbientLight(30);
    SetLong("Бесконечная пустота.");
    SetShort("нигде");
    AddExit("down", ROOM_START);
}
