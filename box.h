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
    bool move(const TetrisGroup& t, Dot dirction);
    bool can_move(const TetrisGroup& t, Dot dirction) const;
    void init_move(Dot d);

    void at_bottom(TetrisGroup* t) const;
    //用于新产生的时候是否判定游戏结束
    bool at_new_check(const TetrisGroup& t) const;
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
Dot find_most_left(const Box* box);
}
#endif//BOX_H
