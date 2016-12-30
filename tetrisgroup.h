#ifndef TETRISGROUP_H
#define TETRISGROUP_H
#include <vector>
#include <memory>
#include "define.h"
#include "dot.h"
#include "box.h"

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
using std::vector;

class TetrisGroup
{
public:
    enum  class PosValue
    {
        NoValue = 0,
        HasValue,
    };
    TetrisGroup(int width, int height);

    // new api
    void up_one_line();

    //the interface for gui
    bool is_alive() const {return alive;}

    void set_clock(ClockDirection d) {clock = d;}
    ClockDirection get_clock() const {return clock;}

    int get_width() const {return my_width;}
    int get_height() const {return my_height;}

    bool move(const Dot& direction);
    bool down(int* lines);
    bool down_to_bottom(int* lines);
    bool turn();
    //the box current and next pointer
    const Box* get_cur_box() const { return cur_box.get(); }
    const Box* get_next_box() const { return next_box.get(); }

    //the interface for box
    bool check_bound(const Dot& d) const;

    PosValue get_matrix_value(const Dot& d) const;

    void set_matrix_value(const Dot& d, PosValue val);

    BoxColor get_matrix_color(const Dot& d) const;

    void set_matrix_color(const Dot& d, BoxColor col);

    void clear_matrix_value(const Dot& d);
    void clear_matrix_color(const Dot& d);

private:
    TetrisGroup(const TetrisGroup&);
    TetrisGroup& operator=(const TetrisGroup&);
    int my_width;
    int my_height;
    std::unique_ptr<Box> cur_box;
    std::unique_ptr<Box> next_box;

    constexpr static int  value_pos = 0;
    constexpr static int  color_pos = 1;


    typedef vector< vector<int> > matrix_2D;
    typedef vector<matrix_2D> matrix_3D;
    matrix_3D matrix;

    void init_matrix(int width, int height);

    int drop_lines();
    void init();

    void clear() {init();}
    void drop_oneline(int y);
    bool is_linefull(int y) const;
    bool alive;
    ClockDirection clock;
};

void get_rand_line(vector<TetrisGroup::PosValue> &vec, int n);

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
    assert(val == PosValue::HasValue || val == PosValue::NoValue);
    assert(check_bound(d));
    matrix[value_pos][d.x][d.y] = int(val);
}

inline BoxColor TetrisGroup::get_matrix_color(const Dot& d) const
{
    assert(check_bound(d));
    return BoxColor(matrix[color_pos][d.x][d.y]);
}

inline void TetrisGroup::set_matrix_color(const Dot& d, BoxColor col)
{
    assert(check_bound(d));
    matrix[color_pos][d.x][d.y] = int(col);
}

inline void TetrisGroup::clear_matrix_value(const Dot& d)
{
    assert(check_bound(d));
    matrix[value_pos][d.x][d.y] = int(PosValue::NoValue);
}

inline void TetrisGroup::clear_matrix_color(const Dot& d)
{
    assert(check_bound(d));
    matrix[color_pos][d.x][d.y] = int(BoxColor::None);
}
}//end of namespace
#endif//TETRISGROUP_H
