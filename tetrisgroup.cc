#include "tetrisgroup.h"
#include "box.h"

namespace Tetris
{
TetrisGroup::TetrisGroup(int width, int height)
    : my_width(width),
      my_height(height),
      cur_box(0),
      next_box(0),
      clock(ClockDirection::ClockWise)
{
    cur_area = static_cast<char*>(malloc(area_size));
    assert(cur_area != NULL);
    next_area = static_cast<char*>(malloc(area_size));
    assert(next_area != NULL);
    cur_area[area_size - 1] = 0;
    next_area[area_size - 1] = 0;

    init();
}
void TetrisGroup::init_matrix(int width, int height)
{
    matrix.resize(2);

    vector<int> vec_val(height, int(NoValue));
    matrix[value_pos] = vector< vector<int> >(width, vec_val);

    vector<int> vec_col(height, int(BoxColor::None));
    matrix[color_pos] = vector< vector<int> >(width, vec_col);
}
TetrisGroup::~TetrisGroup()
{
    //    if (cur_box != 0)
    //    { cur_box->~Box(); }

    //    free(cur_area);

    //    if (next_box != 0)
    //    { next_box->~Box(); }

    //    free(next_area);
    //以前用了“聪明”的方法，用指针来交换指向没有构造的area，
    //但是析构的时候，可能curbox指向的是next_area
    //所以在调用第二次析构的时候就出错了

    if (cur_box != 0)
    { cur_box->~Box(); }

    if (next_box != 0)
    { next_box->~Box(); }

    // 回收放后面
    free(cur_area);
    free(next_area);

}

bool TetrisGroup::turn()
{
    if (!alive)
    { return false; }

    return cur_box->turn(*this, clock);
}

bool TetrisGroup::move(const Dot& direction)
{
    if (!alive)
    { return false; }

    return cur_box->move(*this, direction);
}

void TetrisGroup::init()
{
    alive = true;
    init_matrix(my_width, my_height);

    if (cur_box != 0)
    { cur_box->~Box(); }

    if (next_box != 0)
    { next_box->~Box(); }

    cur_box = get_rand_box((get_width() - 1) / 2, cur_area);
    next_box = get_rand_box((get_width() - 1) / 2, next_area);
    free_area = 0;
}

bool TetrisGroup::is_linefull(int y) const
{
    for (int x = 0; x != get_width(); ++x)
    {
        if (get_matrix_value(x, y) == NoValue)
        { return false; }
    }

    return true;
}

void TetrisGroup::drop_oneline(int y)
{
    for (; y != 0; --y)
    {
        for (int x = 0; x != get_width(); ++x)
        {
            set_matrix_value(x, y , get_matrix_value(x, y - 1));
            set_matrix_color(x, y, get_matrix_color(x, y - 1));
        }
    }

    //初始化最上面一行
    for (int x = 0; x != get_width(); ++x)
    {
        clear_matrix_value(x, 0);
        clear_matrix_color(x, 0);
    }
}
int TetrisGroup::drop_lines()
{
    int dropnum = 0;

    for (int y = get_height() - 1; y >= 0;)
    {
        if (is_linefull(y)) //如果满行，继续判断该行
        {
            drop_oneline(y);
            ++dropnum;
        }
        else //如果此行不消去，则继续向上面扫描
        { --y; }

    }

    return dropnum;
}

void TetrisGroup::swap_cur_next()
{
    //    cur_box->~Box();
    //    cur_box = next_box->CloneTo(cur_area);

    //    next_box->~Box();
    //    next_box = get_rand_box((get_width() - 1) / 2, next_area);
    //用下面的方法可以少一半析构调用
    cur_box->~Box();
    free_area = reinterpret_cast<char*>(cur_box);
    assert(free_area == cur_area || free_area == next_area);

    cur_box = next_box;
    next_box = get_rand_box((get_width() - 1) / 2, free_area);
}

bool TetrisGroup::down(int* lines)
{
    if (!alive)
    { return false; }

    bool b = cur_box->move(*this, MoveDirection::Down);

    if (b)
    { return true; }

    //else
    //向下失败，则根据box类型放置于group内部
    cur_box->at_bottom(this);
    *lines = drop_lines();
    swap_cur_next();

    if (cur_box->at_new_check(*this))
    { return true; }
    else
    {
        alive = false;
        return false;
    }
}
bool TetrisGroup::down_to_bottom(int* lines)
{
    while (cur_box->move(*this, MoveDirection::Down))
        ;

    return down(lines);
}
}
