#include "tetrisgroup.h"
#include "box.h"
#include <algorithm>

namespace Tetris
{
TetrisGroup::TetrisGroup(int width, int height)
    : my_width(width),
      my_height(height),
      clock(ClockDirection::ClockWise)
{
    init();
}

void TetrisGroup::up_one_line()
{
    if (!alive)
        return;


    if (!cur_box->can_move(*this, MoveDirection::Down))
    {
        cur_box->move(*this, MoveDirection::Up);
    }

    vector<TetrisGroup::PosValue> vec(my_width);
    get_rand_line(vec, my_width-3);

    for (int h=0; h<my_height-1; ++h)
    {
        for (int w=0; w<my_width; ++w)
        {
            matrix[value_pos][w][h] = matrix[value_pos][w][h+1];
            matrix[color_pos][w][h] = matrix[color_pos][w][h+1];
        }
    }

    for (int w=0; w<my_width; ++w)
    {
        matrix[value_pos][w][my_height-1] = int(vec[w]);
        matrix[color_pos][w][my_height-1] = int(vec[w]);
    }

}
void TetrisGroup::init_matrix(int width, int height)
{
    matrix.resize(2);

    vector<int> vec_val(height, int(PosValue::NoValue));
    matrix[value_pos] = vector< vector<int> >(width, vec_val);

    vector<int> vec_col(height, int(BoxColor::None));
    matrix[color_pos] = vector< vector<int> >(width, vec_col);
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

    cur_box.reset( get_rand_box((get_width() - 1) / 2) );
    next_box.reset( get_rand_box((get_width() - 1) / 2) );
}

bool TetrisGroup::is_linefull(int y) const
{
    for (int x = 0; x != get_width(); ++x)
    {
        if (get_matrix_value(Dot(x, y)) == PosValue::NoValue)
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
            set_matrix_value(Dot(x, y) , get_matrix_value(Dot(x, y - 1)));
            set_matrix_color(Dot(x, y), get_matrix_color(Dot(x, y - 1)));
        }
    }

    //初始化最上面一行
    for (int x = 0; x != get_width(); ++x)
    {
        Dot d(x, 0);
        clear_matrix_value(d);
        clear_matrix_color(d);
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

    cur_box.swap(next_box);
    next_box.reset( get_rand_box((get_width() - 1) / 2) );

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

void get_rand_line(vector<TetrisGroup::PosValue> &vec, int n)
{
    assert(int(vec.size()) > n);
    std::fill_n(vec.begin(), n, TetrisGroup::PosValue::HasValue);
    std::fill(vec.begin()+n, vec.end(), TetrisGroup::PosValue::NoValue);
    std::random_shuffle(vec.begin(), vec.end());
}

}
