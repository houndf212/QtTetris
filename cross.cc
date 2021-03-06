#include <new>
#include "cross.h"
namespace Tetris
{
/*********************************
##########
#   0
#  123
#   4
#
#
*********************************/
Cross::Cross()
{
    location.resize(size);
    location[0] = Dot(0, 0);

    location[2] = location[0] + MoveDirection::Down;

    location[1] = location[2] + MoveDirection::Left;

    location[3] = location[2] + MoveDirection::Right;

    location[4] = location[2] + MoveDirection::Down;

}

}
