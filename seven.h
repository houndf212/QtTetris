#ifndef SVEN_H
#define SVEN_H
#include "box.h"

namespace Tetris
{
class Seven : public Box
{
public:
    explicit Seven(int status = 0);
    virtual bool turn(const TetrisGroup& t, ClockDirection d);
private:
    virtual int get_size() const { return size; }
    static const int size = 4;
};
}
#endif // SVEN_H
