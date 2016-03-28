#include <new>
#include "five.h"
namespace Tetris
{
/*********************************
  选取  1 2 3 为旋转点， 首选2
  status 0 纵
  status 1 横
##########
#    0
#    1
#--01234---
#    3
#    4
#
#
#
*********************************/

Five::Five(int xstart, int status,  BoxColor::Color col)
    : Box(col)
{
    assert(status == 0 || status == 1);

    if (status == 0)
    {
        location[0] = Dot(xstart, 0);

        location[1] = location[0] + MoveDirection::Down;

        location[2] = location[1] + MoveDirection::Down;

        location[3] = location[2] + MoveDirection::Down;

        location[4] = location[3] + MoveDirection::Down;

    }
    else
    {
        //TODO
        assert(false);
    }
}

bool Five::turn(const TetrisGroup& t, ClockDirection::Direction d)
{
    bool b1 = rotate(t, location[2], d);

    if (b1)
    { return true; }

    bool b2 = rotate(t, location[1], d);

    if(b2)
    { return true; }

    bool b3 = rotate(t, location[3], d);

    if(b3)
    { return true; }

    return false;
}

Five* Five::CloneTo(void* area) const
{
    Five* newfive = new(area) Five(get_color());

    copy_dot(newfive->location, location, location + size);

    return newfive;
}

}
