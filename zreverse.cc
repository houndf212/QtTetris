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

ZReverse::ZReverse(int status)
{
    assert(status == 0);
    location.resize(size);
    if (status == 0)
    {
        location[0] = Dot(0, 0);

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

bool ZReverse::turn(const TetrisGroup& t, ClockDirection d)
{
    return rotate(t, location[1], d) || rotate(t, location[2], d);
}

}

