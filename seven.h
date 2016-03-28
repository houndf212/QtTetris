#ifndef SVEN_H
#define SVEN_H
#include "box.h"

namespace Tetris
{
class Seven : public Box
{
    friend Box* get_rand_box(int xstart, char* area);
public:
    virtual ~Seven() {}
    virtual Seven* CloneTo(void* area) const;
    virtual Dot* begin() { return location; }
    virtual const Dot* begin() const { return location; }
    virtual const Dot* end() const { return location + size;}
    virtual bool turn(const TetrisGroup& t, ClockDirection::Direction d);
private:
    explicit Seven(int xstart, int status = 0, BoxColor::Color col = BoxColor::Seven);
    explicit Seven(BoxColor::Color col): Box(col) {}
    static const int size = 4;
    Dot location[size];
};
}
#endif // SVEN_H
