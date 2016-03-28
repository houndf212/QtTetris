#include <new>
#include "four.h"
namespace Tetris
{
/*********************************
  ѡȡ 1 ���� 2Ϊ��ת�㣬 ��ѡ1
  status 0 ��
  status 1 ��
##########
#    0
#---0123---
#    2
#    3
#
#
#
*********************************/

Four::Four(int xstart, int status,  BoxColor::Color col)
    : Box(col)
{
    assert(status == 0 || status == 1);

    if (status == 0)
    {
        location[0] = Dot(xstart, 0);

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

bool Four::turn(const TetrisGroup& t, ClockDirection::Direction d)
{
    bool b1 = rotate(t, location[1], d);

    if (b1)
    { return true; }

    bool b2 = rotate(t, location[2], d);

    if(b2)
    { return true; }

    return false;
}

Four* Four::CloneTo(void* area) const
{
    Four* newfour = new(area) Four(get_color());

    copy_dot(newfour->location, location, location + size);

    return newfour;
}

}
