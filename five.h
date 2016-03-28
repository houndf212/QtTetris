#ifndef FIVE_H
#define FIVE_H
#include "box.h"

namespace Tetris
{
class Five : public Box
{
    friend Box* get_rand_box(int xstart, char* area);
public:
    virtual ~Five() {}
    virtual Five* CloneTo(void* area) const;
    virtual Dot* begin() { return location; }
    virtual const Dot* begin() const { return location; }
    virtual const Dot* end() const { return location + size;}
    virtual bool turn(const TetrisGroup& t, ClockDirection::Direction d);
private:
    explicit Five(int xstart, int status = 0, BoxColor::Color col = BoxColor::Five);
    explicit Five(BoxColor::Color col): Box(col) {}
    static const int size = 5;
    Dot location[size];
};
}

#endif // FIVE_H
