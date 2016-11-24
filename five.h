#ifndef FIVE_H
#define FIVE_H
#include "box.h"

namespace Tetris
{
class Five : public Box
{
public:
    explicit Five(int status = 0);
    virtual bool turn(const TetrisGroup& t, ClockDirection d);
private:
    static const int size = 5;
};
}

#endif // FIVE_H
