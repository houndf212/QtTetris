#ifndef DOT_H
#define DOT_H
#include "define.h"
namespace Tetris
{

struct Dot
{
    int x;
    int y;
    Dot();
    Dot(int m, int n);
    Dot& operator+=(const Dot& p);
    Dot& operator-=(const Dot& p);
    const Dot rotate(const Dot& center, ClockDirection::Direction clock = ClockDirection::ClockWise) const;
};
namespace MoveDirection
{
const Dot Right(1, 0);
const Dot Left(-1, 0);
const Dot Down(0, 1);
const Dot Up(0, -1);
}
inline Dot::Dot()
    : x(0), y(0)
{
}

inline Dot::Dot(int m, int n)
    : x(m), y(n)
{}

inline Dot& Dot::operator+=(const Dot& d)
{
    this->x += d.x;
    this->y += d.y;
    return *this;
}

inline Dot& Dot::operator-=(const Dot& d)
{
    this->x -= d.x;
    this->y -= d.y;
    return *this;
}
// return const, invalid "a+b=c";
inline const Dot operator+(const Dot& p1, const Dot& p2)
{
    Dot p(p1);
    p += p2;
    return p;
}
// return const, invalid "a-b=c";
inline const Dot operator-(const Dot& p1, const Dot& p2)
{
    Dot p(p1);
    p -= p2;
    return p;
}
// return const, invalid "-a=b";
inline const Dot operator-(const Dot& p)
{
    return Dot(-p.x, -p.y);
}

}
#endif//DOT_H
