#ifndef FOUR_H
#define FOUR_H
#include "box.h"

namespace Tetris
{
class Four : public Box
{
    friend Box* get_rand_box(int xstart, char* area);
public:
    virtual ~Four() {}
    virtual Four* CloneTo(void* area) const;
    virtual Dot* begin() { return location; }
    virtual const Dot* begin() const { return location; }
    virtual const Dot* end() const { return location + size;}
    virtual bool turn(const TetrisGroup& t, ClockDirection::Direction d);
private:
    explicit Four(int xstart, int status = 0, BoxColor::Color col = BoxColor::Four);
    explicit Four(BoxColor::Color col): Box(col) {}
    static const int size = 4;
    Dot location[size];
};
}
#endif // FOUR_H
