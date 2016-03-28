#include <new>
#include "zreverse.h"
namespace Tetris
{
/*********************************
选取 1 或者 2为旋转点， 首选1

status 0 纵
status 1 横
###########
#----0-----
#    12
#     3
#
#
#
*********************************/

ZReverse::ZReverse(int xstart, int status,  BoxColor::Color col)
    : Box(col)
{
    assert(status == 0);

    if (status == 0)
    {
        location[0] = Dot(xstart, 0);

        location[1] = location[0] + MoveDirection::Down;

        location[2] = location[1] + MoveDirection::Right;

        location[3] = location[2] + MoveDirection::Down;
    }
    else
    {
        //TODO other init status
        assert(false);
    }
}

bool ZReverse::turn(const TetrisGroup& t, ClockDirection::Direction d)
{
    bool b1 = rotate(t, location[1], d);

    if (b1)
    { return true; }

    bool b2 = rotate(t, location[2], d);

    if(b2)
    { return true; }

    return false;
}

ZReverse* ZReverse::CloneTo(void* area) const
{
    assert(area != 0);
    ZReverse* newzr = new(area) ZReverse(get_color());

    copy_dot(newzr->location, location, location + size);

    return newzr;
}

}

