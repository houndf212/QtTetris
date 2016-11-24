#ifndef Z_H
#define Z_H
#include "box.h"

namespace Tetris
{
class Z : public Box
{
public:
    explicit Z(int status = 0);
    virtual bool turn(const TetrisGroup& t, ClockDirection d);
private:
    static const int size = 4;
};
}

#endif // Z_H
