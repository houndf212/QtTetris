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

Convex::Convex(int status)
{
    assert(status == 0);
    location.resize(size);
    if (status == 0)
    {
        location[0] = Dot(0, 0);

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

bool Convex::turn(const TetrisGroup& t, ClockDirection d)
{
    return rotate(t, location[1], d) || rotate(t, location[3], d);
}

}

