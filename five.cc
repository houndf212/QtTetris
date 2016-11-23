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

Five::Five(int status)
{
    assert(status == 0 || status == 1);

    if (status == 0)
    {
        location[0] = Dot(0, 0);

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

bool Five::turn(const TetrisGroup& t, ClockDirection d)
{
    return rotate(t, location[2], d) ||
            rotate(t, location[1], d) ||
            rotate(t, location[3], d);
}

}
