#ifndef CONVEX_H
#define CONVEX_H
#include "box.h"

namespace Tetris
{
class Convex : public Box
{
    friend Box* get_rand_box(int xstart, char* area);
public:
    virtual ~Convex() {}
    virtual Convex* CloneTo(void* area) const;
    virtual Dot* begin() { return location; }
    virtual const Dot* begin() const { return location; }
    virtual const Dot* end() const { return location + size;}
    virtual bool turn(const TetrisGroup& t, ClockDirection::Direction d);
private:
    explicit Convex(int xstart, int status = 0, BoxColor::Color col = BoxColor::Convex);
    explicit Convex(BoxColor::Color col): Box(col) {}
    static const int size = 4;
    Dot location[size];
};
}

#endif // CONVEX_H
