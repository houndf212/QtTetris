#include "dot.h"
namespace Tetris
{
Dot Dot::rotate(const Dot& center, ClockDirection clock) const
{
    Dot v = *this - center;
    int tmp = v.x;

    switch (clock)
    {
    case ClockDirection::ClockWise:
        v.x = v.y;
        v.y = -tmp;
        break;

    case ClockDirection::AntiClock:
        v.x = -v.y;
        v.y = tmp;
        break;
    }

    return v + center;
}
}
