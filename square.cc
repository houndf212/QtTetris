#include <new>
#include "square.h"
namespace Tetris
{
/*********************************
##########
#   01
#   32
#
#
#
*********************************/
Square::Square()
{
    location.resize(size);
    location[0] = Dot(0, 0);

    location[1] = location[0] + MoveDirection::Right;

    location[2] = location[1] + MoveDirection::Down;

    location[3] = location[0] + MoveDirection::Down;

}

}
