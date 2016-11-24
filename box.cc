#include "box.h"
#include "tetrisgroup.h"
namespace Tetris
{

bool Box::move(const TetrisGroup& t, Dot dirction)
{
    for(const Dot* p = begin(); p != end(); ++p)
    {
        const Dot next = *p + dirction;

        if (!t.check_bound(next) || t.get_matrix_value(next) == TetrisGroup::HasValue)
        { return false; }
    }

    for (Dot* p = begin(); p != end(); ++p)
    {
        *p += dirction;
    }

    return true;
}

void Box::init_move(Dot d)
{
    for (Dot* p = begin(); p != end(); ++p)
    {
        *p += d;
    }
}

void Box::at_bottom(TetrisGroup* t) const
{
    for (const Dot* p = begin(); p != end(); ++p)
    {
        t->set_matrix_value(*p, TetrisGroup::HasValue);
        t->set_matrix_color(*p, color);
    }
}

bool Box::rotate(const TetrisGroup& t, Dot center, ClockDirection d)
{
    std::vector<Dot> tmp(location.size());
    for (Dot* p = begin(), *k = &tmp[0] ; p != end(); ++p, ++k)
    {
        *k = p->rotate(center, d);

        if (!t.check_bound(*k) || t.get_matrix_value(*k) == TetrisGroup::HasValue)
        { return false; }
    }

    //旋转后的位置可取，然后赋值

    for (Dot* p = begin(), *q = &tmp[0]; p != end(); )
    {
        *p++ = *q++;
    }

    return true;
}

bool Box::at_new_check(const TetrisGroup& t) /*const*/
{
    for (const Dot* p = begin(); p != end(); ++p)
    {
        if (!t.check_bound(*p) || t.get_matrix_value(*p) == TetrisGroup::HasValue)
        {
            return false;
        }
    }

    return true;
}

const Dot find_most_left(const Box* box)
{
    const Dot* d = box->begin();

    for(const Dot* p = box->begin() + 1; p != box->end(); ++p)
    {
        if (d->x > p->x)
        { d = p; }
    }

    return *d;
}

}// end of namespace
