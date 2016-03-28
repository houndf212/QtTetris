#ifndef BOX_H
#define BOX_H
#include "define.h"
#include "dot.h"

namespace Tetris
{

void copy_dot(Dot* to, const Dot* from, const Dot* end);
//前置申明，解决循环依赖
class TetrisGroup;
class Box;
Box* get_rand_box(int xstart, char* area);
class Box
{
    friend Box* get_rand_box(int xstart, char* area);
public:
    virtual ~Box() {}
    virtual const Dot* begin()const = 0;
    virtual const Dot* end()const = 0;
    BoxColor::Color get_color() const { return color;}
    virtual Box* CloneTo(void* area) const = 0;
    virtual bool turn(const TetrisGroup& t, ClockDirection::Direction d) = 0;
    virtual bool move(const TetrisGroup& t, Dot dirction);
    //当box不能down时调用，修改group中矩阵值，设为虚函数的原因是，可能存在 ‘炸弹’这种box
    virtual void at_bottom(TetrisGroup* t) const;
    //用于新产生的时候是否判定游戏结束
    virtual bool at_new_check(const TetrisGroup& t) /*const*/;
protected:
    Box(const Box&);
    Box& operator=(const Box&);
    virtual bool rotate(const TetrisGroup& t, Dot center, ClockDirection::Direction d);
    virtual Dot* begin() = 0;
    explicit Box(BoxColor::Color col): color(col) {}
    BoxColor::Color color;
};
//非内置类型，返回const
const Dot find_most_left(const Box* box);
}
#endif//BOX_H
