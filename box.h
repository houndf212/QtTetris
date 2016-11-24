#ifndef BOX_H
#define BOX_H
#include "define.h"
#include "dot.h"
#include <vector>

namespace Tetris
{

//前置申明，解决循环依赖
class TetrisGroup;
class Box;

Box* get_rand_box(int xstart);

class Box
{
public:
    virtual ~Box() {}
    const Dot* begin()const { return &location[0]; }
    const Dot* end()const  { return begin() + get_size(); }
    BoxColor get_color() const { return color; }
    void set_color(BoxColor c) { color = c; }

    virtual bool turn(const TetrisGroup& t, ClockDirection d) = 0;
    virtual bool move(const TetrisGroup& t, Dot dirction);
    void init_move(Dot d);
    //当box不能down时调用，修改group中矩阵值，设为虚函数的原因是，可能存在 ‘炸弹’这种box
    virtual void at_bottom(TetrisGroup* t) const;
    //用于新产生的时候是否判定游戏结束
    virtual bool at_new_check(const TetrisGroup& t) /*const*/;
protected:
    bool rotate(const TetrisGroup& t, Dot center, ClockDirection d);
    Dot* begin() { return &location[0]; }
    Box(): color(BoxColor::Square) {}
protected:
    std::vector<Dot> location;
private:
    BoxColor color;
    int get_size() const { return location.size(); }
private:
    Box(const Box&) = delete;
    Box& operator=(const Box&) = delete;
};
//非内置类型，返回const
const Dot find_most_left(const Box* box);
}
#endif//BOX_H
