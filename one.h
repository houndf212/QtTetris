#ifndef ONE_H
#define ONE_H
#include "box.h"

namespace Tetris
{
class One : public Box
{
public:
    One();
    virtual bool turn(const TetrisGroup& t, ClockDirection d) { return false; }
    //不是常规box需要自己重写实现
    virtual bool move(const TetrisGroup& t, Dot dirction);
    virtual void at_bottom(TetrisGroup* t) const;
    virtual bool at_new_check(const TetrisGroup& t) /*const*/;
private:
    virtual int get_size() const { return size; }
    static const int size = 1;
    /*mutable*/ bool is_reach;
};
}
#endif // ONE_H
