#ifndef CONVEX_H
#define CONVEX_H
#include "box.h"

namespace Tetris
{
class Convex : public Box
{
public:
    explicit Convex(int status = 0);
    virtual bool turn(const TetrisGroup& t, ClockDirection d);
private:
    static const int size = 4;
};
}

#endif // CONVEX_H
