#include <lib.h>
#include <dirs.h>
#include <virtual.h>

inherit LIB_VIRT_SKY;

static private int XPosition, YPosition, ZPosition;

varargs void SetLongAndItems(int x, int y, int z);

varargs int LimitTravel(int requested, int maximum, int lessthan){
    if(lessthan && requested < maximum) return maximum;
    else if(lessthan && requested > maximum) return requested;
    else if(requested > maximum) return maximum;
    else return requested;
}

varargs static void create(int x, int y, int z) {
    string n, s, e, w, u, d;
    string ne, nw, se, sw;

    int max_north = 10;
    int max_south = 1;
    int max_east = 10;
    int max_west = 1;
    int max_up = 10;
    int max_down = 0;

    SetNoReplace(1);
    virt_sky::create();
    XPosition = x;
    YPosition = y;
    ZPosition = z;
    SetClimate("temperate");
    SetAmbientLight(30);
    SetLongAndItems(x, y, z);
    SetShort("Небеса над плоской равниной.");
    if( x == max_east ) e = "sky/" + (x) + "," + y + "," + z;
    else e = "sky/" + (x+1) + "," + y + "," + z;
    if( x == max_west ) w = "sky/" + (x) + "," + y + "," + z;
    else w = "sky/" + (x-1) + "," + y + "," + z;
    if( y == max_north ) n = "sky/" + x + "," + (y) + "," + z;
    else n = "sky/" + x + "," + (y+1) + "," + z;
    if( y == max_south ) s = "sky/" + x+ "," + (y) + "," + z;
    else s = "sky/" + x + "," + (y-1) + "," + z;
    if( z == max_up ) u = "sky/" + x + "," + y + "," + (z);
    else u = "sky/" + x + "," + y + "," + (z+1);
    if( z == max_down ) d = "sky/" + x+ "," + (y) + "," + z;
    else d = "sky/" + x + "," + y + "," + (z-1);

    nw = "sky/" + LimitTravel(x - 1, max_west, 1) + "," + LimitTravel(y+1, max_north)+ "," + z;
    ne = "sky/" + LimitTravel(x + 1, max_east) + "," + LimitTravel(y+1, max_north)+ "," + z;
    sw = "sky/" + LimitTravel(x - 1, max_west, 1) + "," + LimitTravel(y-1, max_south, 1)+ "," + z;
    se = "sky/" + LimitTravel(x + 1, max_east) + "," + LimitTravel(y-1, max_south, 1)+ "," + z;

    SetGoMessage("Вы не можете переместиться туда.");

    if( n ) AddExit("north", __DIR__ + n);
    if( s ) AddExit("south", __DIR__ + s);
    if( e ) AddExit("east", __DIR__ + e);
    if( w ) AddExit("west", __DIR__ + w);
    if( u ) AddExit("up", __DIR__ + u);
    if( d ) AddExit("down", __DIR__ + d);
    if( ne ) AddExit("northeast", __DIR__ + ne);
    if( nw ) AddExit("northwest", __DIR__ + nw);
    if( se ) AddExit("southeast", __DIR__ + se);
    if( sw ) AddExit("southwest", __DIR__ + sw);

    if(z == 1){
        RemoveExit("down");
        AddExit("down", __DIR__ + "arena/" + x + "," + y);
    }

#if 1
    if(y == 1){
        RemoveExit("south");
        RemoveExit("southeast");
        RemoveExit("southwest");
    }
    else if(y == 10){
        RemoveExit("north");
        RemoveExit("northeast");
        RemoveExit("northwest");
    }
    if(x == 1){
        RemoveExit("west");
        RemoveExit("northwest");
        RemoveExit("southwest");
    }
    if(x == 10){
        RemoveExit("east");
        RemoveExit("northeast");
        RemoveExit("southeast");
    }
#endif
}

varargs void SetLongAndItems(int x, int y, int z) {
    mapping inv, items;
    string str;
    ::SetLongAndItems(x, y, z);

    inv = ([]);
    str = "Вы в небе над огромной плоской равниной, окруженной со всех сторон "
        "каменными стенами. Это похоже на большую арену для схваток между пешими "
        "и верховыми противниками.";
    if(query_night()) str += " Звезды ночного неба сверкают над головой.";
    if(x == 1) str += " Каменная стена не дает переместиться дальше на запад.";
    if(x == 10) str += " Каменная стена не дает переместиться дальше на восток.";
    if(y == 1) str += " Каменная стена не дает переместиться дальше на юг.";
    if(y == 10) str += " Каменная стена не дает переместиться дальше на север.";
    if(x == 5 && y == 1) str += "\n%^GREEN%^Здесь есть табличка, которую вы можете прочесть.%^RESET%^";

    SetItems( ([ "арена" : "Место насильственной смерти и великого разрушения.",
                ]) );

    if(y == 10) {
        AddItem( ({ "каменная стена","стена","огромная стена"}), 
                "Эта огромная каменная стена препятствует дальнейшему путешествию на север." );
    }
    else if(y == 1) {
        AddItem( ({ "каменная стена","стена","огромная стена"}),
                "Эта огромная каменная стена препятствует дальнейшему путешествию на юг." );
    }

    if(x == 10) {
        AddItem( ({ "каменная стена","стена","огромная стена"}),
                "Эта огромная каменная стена препятствует дальнейшему путешествию на восток." );
    }
    if(x == 1) {
        AddItem( ({ "каменная стена","стена","огромная стена"}),
                "Эта огромная каменная стена препятствует дальнейшему путешествию на запад." );
    }
    AddItem( ({ "стены","каменные стены","огромные стены" }),
            "Большие стены образуют границы этого убийственного поля." );
    SetLong(str);
    SetDayLight(30);
    SetNightLight(30);
}
