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

Seven::Seven(int xstart, int status,  BoxColor::Color col)
    : Box(col)
{
    assert(status == 0);

    if (status == 0)
    {
        location[0] = Dot(xstart, 0);

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

bool Seven::turn(const TetrisGroup& t, ClockDirection::Direction d)
{
    bool b1 = rotate(t, location[2], d);

    if (b1)
    { return true; }

    bool b2 = rotate(t, location[1], d);

    if (b2)
    { return true; }

    return false;
}

Seven* Seven::CloneTo(void* area) const
{
    assert(area != 0);
    Seven* newseven = new(area) Seven(get_color());

    copy_dot(newseven->location, location, location + size);

    return newseven;
}

}
