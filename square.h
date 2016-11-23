#ifndef SQUARE_H
#define SQUARE_H
#include "box.h"

namespace Tetris
{
class Square : public Box
{
public:
    Square();
    virtual bool turn(const TetrisGroup& t, ClockDirection d) { return false; }
private:
    virtual int get_size() const { return size; }
    static const int size = 4;
};
}
#endif//SQUARE_H
