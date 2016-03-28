#include <new>
#include "three.h"

namespace Tetris
{
/*********************************
  选取  1 0 2 为旋转点， 首选1
  status 0 纵
  status 1 横
##########
#    0
#---012---
#    2
#
#
#
#
*********************************/

Three::Three(int xstart, int status,  BoxColor::Color col)
    : Box(col)
{
    assert(status == 0 || status == 1);

    if (status == 0)
    {
        location[0] = Dot(xstart, 0);

        location[1] = location[0] + MoveDirection::Down;

        location[2] = location[1] + MoveDirection::Down;
    }
    else
    {
        //TODO
        assert(false);
    }
}

bool Three::turn(const TetrisGroup& t, ClockDirection::Direction d)
{
    bool b1 = rotate(t, location[1], d);

    if (b1)
    { return true; }

    bool b2 = rotate(t, location[0], d);

    if(b2)
    { return true; }

    bool b3 = rotate(t, location[2], d);

    if(b3)
    { return true; }

    return false;
}

Three* Three::CloneTo(void* area) const
{
    Three* newthree = new(area) Three(get_color());

    copy_dot(newthree->location, location, location + size);

    return newthree;
}

}
