#ifndef SEVENREVERSE_H
#define SEVENREVERSE_H
#include "box.h"

namespace Tetris
{
class SevenReverse : public Box
{
public:
    explicit SevenReverse(int status = 0);
    virtual bool turn(const TetrisGroup& t, ClockDirection d);
private:
    virtual int get_size() const { return size; }
    static const int size = 4;
};
}
#endif // SEVENREVERSE_H
