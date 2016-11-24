#include <new>
#include "one.h"
#include "tetrisgroup.h"
namespace Tetris
{
/*********************************
#########
#   0
#
#
#
#
*********************************/
One::One()
    :is_reach(false)
{
    location.resize(size);
    location[0] = Dot(0, 0);
}

bool One::move(const TetrisGroup& t, Dot dirction)
{
    if (is_reach)
    { return false; }

    const Dot d = location[0] + dirction;

    if (!t.check_bound(d))
    { return false; }

    if (t.get_matrix_value(d) == TetrisGroup::HasValue)
    { is_reach = true; }

    location[0] += dirction;
    return true;
}

void One::at_bottom(TetrisGroup* t) const
{
    t->clear_matrix_value(location[0]);
    t->clear_matrix_color(location[0]);
}

bool One::at_new_check(const TetrisGroup& t) /*const*/
{
    if (t.get_matrix_value(location[0]) == TetrisGroup::HasValue)
    { is_reach = true; }

    return true;
}

}

