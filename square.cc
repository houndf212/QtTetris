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
Square::Square(int xstart, BoxColor::Color col)
    : Box(col)
{
    location[0] = Dot(xstart, 0);

    location[1] = location[0] + MoveDirection::Right;

    location[2] = location[1] + MoveDirection::Down;

    location[3] = location[0] + MoveDirection::Down;

}

Square* Square::CloneTo(void* area) const
{
    assert(area != 0);
    Square* newsquare = new(area) Square(this->get_color());

    //for speed, use bits copy, but something is wrong = =!
    //strncpy(reinterpret_cast<char*>(p->location), reinterpret_cast<const char*>(this->location), sizeof(this->location));
    copy_dot(newsquare->location, location, location + size);

    return newsquare;
}
}
