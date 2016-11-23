#include <new>
#include "four.h"
namespace Tetris
{
/*********************************
  选取 1 或者 2为旋转点， 首选1
  status 0 纵
  status 1 横
##########
#    0
#---0123---
#    2
#    3
#
#
#
*********************************/

Four::Four(int status)
{
    assert(status == 0 || status == 1);

    if (status == 0)
    {
        location[0] = Dot(0, 0);

        location[1] = location[0] + MoveDirection::Down;

        location[2] = location[1] + MoveDirection::Down;

        location[3] = location[2] + MoveDirection::Down;
    }
    else
    {
        //TODO
        assert(false);

    }
}

bool Four::turn(const TetrisGroup& t, ClockDirection d)
{
    return rotate(t, location[1], d) || rotate(t, location[2], d);
}

}
