#ifndef FOUR_H
#define FOUR_H
#include "box.h"

namespace Tetris
{
class Four : public Box
{
public:
    Four(int status = 0);
    virtual bool turn(const TetrisGroup& t, ClockDirection d);
private:
    static const int size = 4;
};
}
#endif // FOUR_H
