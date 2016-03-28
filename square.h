#ifndef SQUARE_H
#define SQUARE_H
#include "box.h"

namespace Tetris
{
class Square : public Box
{
    friend Box* get_rand_box(int xstart, char* area);
public:
    virtual ~Square() {}
    virtual Square* CloneTo(void* area) const;
    virtual Dot* begin() { return location; }
    virtual const Dot* begin() const { return location; }
    virtual const Dot* end() const { return location + size;}
    virtual bool turn(const TetrisGroup& t, ClockDirection::Direction d) { return false; }
private:
    explicit Square(int xstart, BoxColor::Color col = BoxColor::Square);
    explicit Square(BoxColor::Color col): Box(col) {}
    static const int size = 4;
    Dot location[size];
};
}
#endif//SQUARE_H
