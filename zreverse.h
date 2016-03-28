#ifndef ZREVERSE_H
#define ZREVERSE_H
#include "box.h"

namespace Tetris
{
class ZReverse : public Box
{
    friend Box* get_rand_box(int xstart, char* area);
public:
    virtual ~ZReverse() {}
    virtual ZReverse* CloneTo(void* area) const;
    virtual Dot* begin() { return location; }
    virtual const Dot* begin() const { return location; }
    virtual const Dot* end() const { return location + size;}
    virtual bool turn(const TetrisGroup& t, ClockDirection::Direction d);
private:
    explicit ZReverse(int xstart, int status = 0, BoxColor::Color col = BoxColor::ZReverse);
    explicit ZReverse(BoxColor::Color col): Box(col) {}
    static const int size = 4;
    Dot location[size];
};
}

#endif // ZREVERSE_H
