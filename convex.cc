#include <new>
#include "convex.h"

namespace Tetris
{
/*********************************
  选取  1, 3为旋转点， 首选 1


############
#----012---
#     3
#
#
#
#
*********************************/

Convex::Convex(int xstart, int status,  BoxColor::Color col)
    : Box(col)
{
    assert(status == 0);

    if (status == 0)
    {
        location[0] = Dot(xstart, 0);

        location[1] = location[0] + MoveDirection::Right;

        location[2] = location[1] + MoveDirection::Right;

        location[3] = location[1] + MoveDirection::Down;
    }
    else
    {
        //TODO other init status
        assert(false);
    }
}

bool Convex::turn(const TetrisGroup& t, ClockDirection::Direction d)
{
    bool b1 = rotate(t, location[1], d);

    if (b1)
    { return true; }

    bool b2 = rotate(t, location[3], d);

    if (b2)
    { return true; }

    return false;
}

Convex* Convex::CloneTo(void* area) const
{
    assert(area != 0);
    Convex* convex = new(area) Convex(get_color());

    copy_dot(convex->location, location, location + size);

    return convex;
}

}

