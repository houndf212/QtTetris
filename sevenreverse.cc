#include <new>
#include "sevenreverse.h"

namespace Tetris
{
/*********************************
  //选取 1 或者 2为旋转点， 首选2
  选取  2为旋转点
  status 0 纵
  status 1 横
###########
#----10----
#    2
#    3
#
#
#
*********************************/

SevenReverse::SevenReverse(int status)
{
    assert(status == 0);
    location.resize(size);
    if (status == 0)
    {
        location[0] = Dot(0 + 1, 0);

        location[1] = location[0] + MoveDirection::Left;

        location[2] = location[1] + MoveDirection::Down;

        location[3] = location[2] + MoveDirection::Down;
    }
    else
    {
        //TODO other init status
        assert(false);
    }
}

bool SevenReverse::turn(const TetrisGroup& t, ClockDirection d)
{
    return rotate(t, location[2], d) ||
            rotate(t, location[1], d) ||
            rotate(t, location[3], d);
}

}
