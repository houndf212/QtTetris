#ifndef THREE_H
#define THREE_H
#include "box.h"

namespace Tetris
{
class Three : public Box
{
public:
    explicit Three(int status = 0);
    virtual bool turn(const TetrisGroup& t, ClockDirection d);
private:
    virtual int get_size() const { return size; }
    static const int size = 3;
};
}

#endif // THREE_H
