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

Box* get_rand_box(int xstart, char* area)
{
    assert(area != 0);
    const unsigned int area_size = TetrisGroup::area_size;
    assert(area_size > sizeof(Square));
    assert(area_size > sizeof(Four));
    assert(area_size > sizeof(Seven));
    assert(area_size > sizeof(SevenReverse));
    assert(area_size > sizeof(Z));
    assert(area_size > sizeof(ZReverse));
    assert(area_size > sizeof(Convex));
    assert(area_size > sizeof(One));
    assert(area_size > sizeof(Five));
    assert(area_size > sizeof(Three));
    assert(area_size > sizeof(Cross));

    int r = std::rand() % BoxColor::BoxNum;
    r += 1;
    assert(0 < r && r <= BoxColor::BoxNum);
    BoxColor::Color c = BoxColor::Color(r);
    Box* box;

    switch (c)
    {
    case BoxColor::Square:
        box = new(area) Square(xstart);
        break;

    case BoxColor::Four:
        box = new(area) Four(xstart);
        break;

    case BoxColor::Seven:
        box = new(area) Seven(xstart);
        break;

    case BoxColor::SevenReverse:
        box = new(area) SevenReverse(xstart);
        break;

    case BoxColor::Z:
        box = new(area) Z(xstart);
        break;

    case BoxColor::ZReverse:
        box = new(area) ZReverse(xstart);
        break;

    case BoxColor::Convex:
        box = new(area) Convex(xstart);
        break;

    case BoxColor::One:
        box = new(area) One(xstart);
        break;

    case BoxColor::Five:
        box = new(area) Five(xstart);
        break;

    case BoxColor::Three:
        box = new(area) Three(xstart);
        break;

    case BoxColor::Cross:
        box = new(area) Cross(xstart);
        break;

    default:
        box = new(area) Cross(xstart);
        break;
    }

    return box;
}
}
