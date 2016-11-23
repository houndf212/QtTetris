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

Three::Three(int status)
{
    assert(status == 0 || status == 1);

    if (status == 0)
    {
        location[0] = Dot(0, 0);

        location[1] = location[0] + MoveDirection::Down;

        location[2] = location[1] + MoveDirection::Down;
    }
    else
    {
        //TODO
        assert(false);
    }
}

bool Three::turn(const TetrisGroup& t, ClockDirection d)
{
    return rotate(t, location[1], d) ||
            rotate(t, location[0], d) ||
            rotate(t, location[2], d);
}

}
