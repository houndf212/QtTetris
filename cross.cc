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
Cross::Cross(int xstart, BoxColor::Color col)
    : Box(col)
{
    location[0] = Dot(xstart, 0);

    location[2] = location[0] + MoveDirection::Down;

    location[1] = location[2] + MoveDirection::Left;

    location[3] = location[2] + MoveDirection::Right;

    location[4] = location[2] + MoveDirection::Down;

}

Cross* Cross::CloneTo(void* area) const
{
    assert(area != 0);
    Cross* newcorss = new(area) Cross(this->get_color());

    copy_dot(newcorss->location, location, location + size);

    return newcorss;
}
}
