#ifndef BOX_H
#define BOX_H
#include "define.h"
#include "dot.h"
#include <memory>

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
    const Dot* begin()const { return location; }
    const Dot* end()const  { return location + get_size(); }
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
    Dot* begin() { return location; }
    Box(): color(BoxColor::Square) {}

protected:
//    std::unique_ptr<Dot[], std::default_delete<Dot[]>> location;
    constexpr static int max_size = 8;
    Dot location[max_size];
private:
    BoxColor color;
    virtual int get_size() const = 0;
private:
    Box(const Box&);
    Box& operator=(const Box&);
};
//非内置类型，返回const
const Dot find_most_left(const Box* box);
}
#endif//BOX_H
