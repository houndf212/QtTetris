#ifndef Z_H
#define Z_H
#include "box.h"

namespace Tetris
{
class Z : public Box
{
    friend Box* get_rand_box(int xstart, char* area);
public:
    virtual ~Z() {}
    virtual Z* CloneTo(void* area) const;
    virtual Dot* begin() { return location; }
    virtual const Dot* begin() const { return location; }
    virtual const Dot* end() const { return location + size;}
    virtual bool turn(const TetrisGroup& t, ClockDirection::Direction d);
private:
    explicit Z(int xstart, int status = 0, BoxColor::Color col = BoxColor::Z);
    explicit Z(BoxColor::Color col): Box(col) {}
    static const int size = 4;
    Dot location[size];
};
}

#endif // Z_H
