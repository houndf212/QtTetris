#ifndef TETRISGROUP_H
#define TETRISGROUP_H
#include <vector>
#include <QDebug>
#include "define.h"
#include "dot.h"

/*********************************
 0  ...........width(max_x)
 |  ################
 |  #
 |  #
 |  #
 |  #
 |  #
 |  #
 |  ################
 height(max_y)
**********************************/

namespace Tetris
{
class Box;
using std::vector;

class TetrisGroup
{
public:
    enum PosValue
    {
        NoValue = 0,
        HasValue,
    };
    TetrisGroup(int width, int height);
    ~TetrisGroup();

    //the interface for gui
    BoxColor::Color operator()(int x, int y) const;
    bool is_alive() const {return alive;}

    void set_clock(ClockDirection::Direction d) {clock = d;}
    ClockDirection::Direction get_clock() const {return clock;}

    int get_width() const {return my_width;}
    int get_height() const {return my_height;}

    bool move(const Dot& direction);
    bool down(int* lines);
    bool down_to_bottom(int* lines);
    bool turn();
    //the box current and next pointer
    const Box* get_cur_box() const { return cur_box; }
    const Box* get_next_box() const { return next_box; }

    //the interface for box
    bool check_bound(const Dot& d) const;

    PosValue get_matrix_value(const Dot& d) const;
    PosValue get_matrix_value(int x, int y) const { return get_matrix_value(Dot(x, y)); }
    void set_matrix_value(const Dot& d, PosValue val);
    void set_matrix_value(int x, int y, PosValue val) { set_matrix_value(Dot(x, y), val); }
    BoxColor::Color get_matrix_color(const Dot& d) const;
    BoxColor::Color get_matrix_color(int x, int y) const { return get_matrix_color(Dot(x, y)); }
    void set_matrix_color(const Dot& d, BoxColor::Color col);
    void set_matrix_color(int x, int y, BoxColor::Color col) { set_matrix_color(Dot(x, y), col); }
    void clear_matrix_value(const Dot& d);
    void clear_matrix_value(int x, int y) { clear_matrix_value(Dot(x, y)); }
    void clear_matrix_color(const Dot& d);
    void clear_matrix_color(int x, int y) { clear_matrix_color(Dot(x, y)); }
private:
    TetrisGroup(const TetrisGroup&);
    TetrisGroup& operator=(const TetrisGroup&);
    int my_width;
    int my_height;
    Box* cur_box;
    Box* next_box;
    enum Pos_Type
    {
        value_pos = 0,
        color_pos,
    };
    typedef vector< vector<int> > matrix_2D;
    //matrix[Pos_Type][width][height]
    typedef vector<matrix_2D> matrix_3D;
    matrix_3D matrix;
    //const matrix_2D& value_matrix() const;
    //const matrix_2D& color_matrix() const;
    //matrix_2D& value_matrix();
    //matrix_2D& color_matrix();

    void init_matrix(int width, int height);

    int drop_lines();
    void init();
    void swap_cur_next();
    void clear() {init();}
    void drop_oneline(int y);
    bool is_linefull(int y) const;
    bool alive;
    ClockDirection::Direction clock;

public:
    static const unsigned int area_size = 64;
private:
    /***********************************
      2014-12-1 19:31:13
      in book <<exceptional C++>>, says, the pointer of cur_area
      or next_area may not be align, means int(cur_area)%4!=0, so
      the *cur_area, may be lose fasty.
      由于area不是动态分配的，它的指针边界值可能不是偶数，或者4的倍数，cpu取地址值的时候
      会变得很慢， 一般静态分配数组，或者动态分配new malloc 分配的指针都是对齐了的。
      所以这里采用例外的方法
    ***********************************/
    char* cur_area;
    char* next_area;
    char* free_area;
    //char shadow_area[area_size];
};

inline BoxColor::Color TetrisGroup::operator()(int x, int y) const
{
    return get_matrix_color(x, y);
}

inline bool TetrisGroup::check_bound(const Dot& d) const
{
    return 0 <= d.x && d.x < get_width() && 0 <= d.y && d.y < get_height();
}

inline TetrisGroup::PosValue TetrisGroup::get_matrix_value(const Dot& d) const
{
    assert(check_bound(d));
    return PosValue(matrix[value_pos][d.x][d.y]);
}

inline void TetrisGroup::set_matrix_value(const Dot& d, PosValue val)
{
    assert(val == HasValue || val == NoValue);
    assert(check_bound(d));
    matrix[value_pos][d.x][d.y] = val;
}

inline BoxColor::Color TetrisGroup::get_matrix_color(const Dot& d) const
{
    assert(check_bound(d));
    return BoxColor::Color(matrix[color_pos][d.x][d.y]);
}

inline void TetrisGroup::set_matrix_color(const Dot& d, BoxColor::Color col)
{
    assert(check_bound(d));
    matrix[color_pos][d.x][d.y] = col;
}

inline void TetrisGroup::clear_matrix_value(const Dot& d)
{
    assert(check_bound(d));
    matrix[value_pos][d.x][d.y] = NoValue;
}

inline void TetrisGroup::clear_matrix_color(const Dot& d)
{
    assert(check_bound(d));
    matrix[color_pos][d.x][d.y] = BoxColor::None;
}
}//end of namespace
#endif//TETRISGROUP_H
