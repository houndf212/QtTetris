#ifndef SEVENREVERSE_H
#define SEVENREVERSE_H
#include "box.h"

namespace Tetris
{
class SevenReverse : public Box
{
    friend Box* get_rand_box(int xstart, char* area);
public:
    virtual ~SevenReverse() {}
    virtual SevenReverse* CloneTo(void* area) const;
    virtual Dot* begin() { return location; }
    virtual const Dot* begin() const { return location; }
    virtual const Dot* end() const { return location + size;}
    virtual bool turn(const TetrisGroup& t, ClockDirection::Direction d);
private:
    explicit SevenReverse(int xstart, int status = 0, BoxColor::Color col = BoxColor::SevenReverse);
    explicit SevenReverse(BoxColor::Color col): Box(col) {}
    static const int size = 4;
    Dot location[size];
};
}
#endif // SEVENREVERSE_H
