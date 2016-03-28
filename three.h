#ifndef THREE_H
#define THREE_H
#include "box.h"

namespace Tetris
{
class Three : public Box
{
    friend Box* get_rand_box(int xstart, char* area);
public:
    virtual ~Three() {}
    virtual Three* CloneTo(void* area) const;
    virtual Dot* begin() { return location; }
    virtual const Dot* begin() const { return location; }
    virtual const Dot* end() const { return location + size;}
    virtual bool turn(const TetrisGroup& t, ClockDirection::Direction d);
private:
    explicit Three(int xstart, int status = 0, BoxColor::Color col = BoxColor::Five);
    explicit Three(BoxColor::Color col): Box(col) {}
    static const int size = 3;
    Dot location[size];
};
}

#endif // THREE_H
