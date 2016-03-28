#ifndef CROSS_H
#define CROSS_H
#include "box.h"

namespace Tetris
{
class Cross : public Box
{
    friend Box* get_rand_box(int xstart, char* area);
public:
    virtual ~Cross() {}
    virtual Cross* CloneTo(void* area) const;
    virtual Dot* begin() { return location; }
    virtual const Dot* begin() const { return location; }
    virtual const Dot* end() const { return location + size;}
    virtual bool turn(const TetrisGroup& t, ClockDirection::Direction d) { return false; }
private:
    explicit Cross(int xstart, BoxColor::Color col = BoxColor::Cross);
    explicit Cross(BoxColor::Color col): Box(col) {}
    static const int size = 5;
    Dot location[size];
};
}

#endif // CROSS_H
