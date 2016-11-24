#ifndef ZREVERSE_H
#define ZREVERSE_H
#include "box.h"

namespace Tetris
{
class ZReverse : public Box
{
public:
    explicit ZReverse(int status = 0);
    virtual bool turn(const TetrisGroup& t, ClockDirection d);
private:
    static const int size = 4;
};
}

#endif // ZREVERSE_H
