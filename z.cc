#include <new>
#include "z.h"
namespace Tetris
{
/*********************************
  选取 1 或者 2为旋转点， 首选1

  status 0 纵
  status 1 横
###########
#---01-----
#    23
#
#
#
#
*********************************/

Z::Z(int xstart, int status,  BoxColor::Color col)
    : Box(col)
{
    assert(status == 0);

    if (status == 0)
    {
        location[0] = Dot(xstart - 1, 0);

        location[1] = location[0] + MoveDirection::Right;

        location[2] = location[1] + MoveDirection::Down;

        location[3] = location[2] + MoveDirection::Right;
    }
    else
    {
        //TODO other init status
        assert(false);
    }
}

bool Z::turn(const TetrisGroup& t, ClockDirection::Direction d)
{
    bool b1 = rotate(t, location[1], d);

    if (b1)
    { return true; }

    bool b2 = rotate(t, location[2], d);

    if(b2)
    { return true; }

    return false;
}

Z* Z::CloneTo(void* area) const
{
    assert(area != 0);
    Z* newz = new(area) Z(get_color());

    copy_dot(newz->location, location, location + size);

    return newz;
}

}
