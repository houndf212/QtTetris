#ifndef CROSS_H
#define CROSS_H
#include "box.h"

namespace Tetris
{
class Cross : public Box
{
public:
    Cross();
    virtual bool turn(const TetrisGroup& t, ClockDirection d) { return false; }
private:
    virtual int get_size() const { return size; }
    static const int size = 5;
};
}

#endif // CROSS_H
