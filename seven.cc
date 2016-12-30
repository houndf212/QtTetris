#include <new>
#include "seven.h"
namespace Tetris
{
/*********************************
  //选取 1 或者 2为旋转点， 首选2
  选取  2为旋转点
  status 0 纵
  status 1 横
###########
#---01-----
#    2
#    3
#
#
#
*********************************/

Seven::Seven(int status)
{
    assert(status == 0);
    location.resize(size);
    if (status == 0)
    {
        location[0] = Dot(0, 0);

        location[1] = location[0] + MoveDirection::Right;

        location[2] = location[1] + MoveDirection::Down;

        location[3] = location[2] + MoveDirection::Down;
    }
    else
    {
        //TODO other init status
        assert(false);
    }
}

bool Seven::turn(const TetrisGroup& t, ClockDirection d)
{
    return rotate(t, location[2], d) || rotate(t, location[1], d);
}

}
