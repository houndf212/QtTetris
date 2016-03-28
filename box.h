#ifndef BOX_H
#define BOX_H
#include "define.h"
#include "dot.h"

namespace Tetris
{

void copy_dot(Dot* to, const Dot* from, const Dot* end);
//ǰ�����������ѭ������
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
    //��box����downʱ���ã��޸�group�о���ֵ����Ϊ�麯����ԭ���ǣ����ܴ��� ��ը��������box
    virtual void at_bottom(TetrisGroup* t) const;
    //�����²�����ʱ���Ƿ��ж���Ϸ����
    virtual bool at_new_check(const TetrisGroup& t) /*const*/;
protected:
    Box(const Box&);
    Box& operator=(const Box&);
    virtual bool rotate(const TetrisGroup& t, Dot center, ClockDirection::Direction d);
    virtual Dot* begin() = 0;
    explicit Box(BoxColor::Color col): color(col) {}
    BoxColor::Color color;
};
//���������ͣ�����const
const Dot find_most_left(const Box* box);
}
#endif//BOX_H
