#include <cstdlib>
#include <new>
#include <cstring>
#include "box.h"
#include "square.h"
#include "four.h"
#include "seven.h"
#include "sevenreverse.h"
#include "z.h"
#include "zreverse.h"
#include "convex.h"
#include "one.h"
#include "five.h"
#include "three.h"
#include "cross.h"
#include "tetrisgroup.h" //to use TetrisGroup::area_size

namespace Tetris
{

Box* get_rand_box(int xstart)
{
    int r = std::rand() % int(BoxColor::BoxNum);
    r += 1;
    assert(0 < r && r <= int(BoxColor::BoxNum));
    BoxColor c = BoxColor(r);
    Box* box;

    switch (c)
    {
    case BoxColor::Square:
        box = new Square();
        break;

    case BoxColor::Four:
        box = new Four();
        break;

    case BoxColor::Seven:
        box = new Seven();
        break;

    case BoxColor::SevenReverse:
        box = new SevenReverse();
        break;

    case BoxColor::Z:
        box = new Z();
        break;

    case BoxColor::ZReverse:
        box = new ZReverse();
        break;

    case BoxColor::Convex:
        box = new Convex();
        break;

//    case BoxColor::One:
//        box = new One();
//        break;

    case BoxColor::Five:
        box = new Five();
        break;

    case BoxColor::Three:
        box = new Three();
        break;

    case BoxColor::Cross:
        box = new Cross();
        break;

    default:
        box = new Cross();
        break;
    }
    box->set_color(c);
    box->init_move(Dot(xstart, 0));
    return box;
}

}
