#ifndef ONE_H
#define ONE_H
#include "box.h"

namespace Tetris
{
class One : public Box
{
    friend Box* get_rand_box(int xstart, char* area);
public:
    virtual ~One() {}
    virtual One* CloneTo(void* area) const;
    virtual Dot* begin() { return location; }
    virtual const Dot* begin() const { return location; }
    virtual const Dot* end() const { return location + size;}
    virtual bool turn(const TetrisGroup& t, ClockDirection::Direction d) { return false; }
    //不是常规box需要自己重写实现
    virtual bool move(const TetrisGroup& t, Dot dirction);
    virtual void at_bottom(TetrisGroup* t) const;
    virtual bool at_new_check(const TetrisGroup& t) /*const*/;
private:
    explicit One(int xstart, BoxColor::Color col = BoxColor::One);
    explicit One(BoxColor::Color col): Box(col) {}
    static const int size = 1;
    Dot location[size];
    /*mutable*/ bool is_reach;
};
}
#endif // ONE_H
