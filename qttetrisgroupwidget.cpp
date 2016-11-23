#include <QPaintEvent>
#include <QPainter>
#include <QRect>
#include "qttetrisgroupwidget.h"
#include "box.h"
#include "dot.h"

extern QColor trans_color(Tetris::BoxColor color);

QtTetrisGroupWidget::QtTetrisGroupWidget(const Tetris::TetrisGroup& g, QWidget* parent) :
    QWidget(parent),
    group(g),
    my_width(group.get_width()*my_blocksize),
    my_height(group.get_height()*my_blocksize)
{
}

void QtTetrisGroupWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    const QRect out_rect(2, 2, width() - 4, height() - 4);
    painter.drawRect(out_rect);
    painter.setViewport(4, 4, width() - 8, height() - 8);

    painter.setWindow(0, 0, my_width, my_height);
    draw_group(&painter);
    draw_curbox(&painter);
    draw_alignlines(&painter);
}

Tetris::Dot QtTetrisGroupWidget::find_most_left(const Tetris::Box* box) const
{
    const Tetris::Dot* d = box->begin();

    for(const Tetris::Dot* p = box->begin() + 1; p != box->end(); ++p)
    {
        if (d->x > p->x)
        { d = p; }
    }

    return *d;
}

void QtTetrisGroupWidget::draw_oneblock(QPainter* p, const Tetris::Dot& d, QColor color)
{
    const int block_alig = 0;

    //p->setPen(color);
    p->setBrush(color);
    const QRect rect(d.x * my_blocksize + block_alig,
                     d.y * my_blocksize + block_alig,
                     my_blocksize - 2 * block_alig,
                     my_blocksize - 2 * block_alig);
    p->drawRect(rect);
}

void QtTetrisGroupWidget::draw_group(QPainter* p)
{
    for (int x = 0; x != group.get_width(); ++x)
    {
        for (int y = 0; y != group.get_height(); ++y)
        {
            Tetris::Dot d(x, y);
            if (Tetris::BoxColor::None == group.get_matrix_color(d))
            { continue; }

            draw_oneblock(p, Tetris::Dot(x, y), trans_color(group.get_matrix_color(d)));
        }
    }
}

void QtTetrisGroupWidget::draw_curbox(QPainter* painter)
{
    const Tetris::Box* box = group.get_cur_box();

    for (const Tetris::Dot* p = box->begin(); p != box->end(); ++p)
    {
        draw_oneblock(painter, *p, trans_color(box->get_color()));
    }
}

void QtTetrisGroupWidget::draw_alignlines(QPainter* painter)
{
    const Tetris::Box* box = group.get_cur_box();
    Tetris::Dot left_top = *box->begin();
    Tetris::Dot right_top = *box->begin();

    for(const Tetris::Dot* p = box->begin() + 1; p != box->end(); ++p)
    {
        if (p->x < left_top.x)
        { left_top = *p; }
        else if (p->x == left_top.x)
        {
            if (left_top.y < p->y)
            { left_top = *p; }
        }

        if (p->x > right_top.x)
        { right_top = *p; }
        else if (p->x == right_top.x)
        {
            if (right_top.y < p->y)
            { right_top = *p; }
        }
    }

    ++left_top.y;
    right_top += Tetris::Dot(1, 1);

    QLine left_line(left_top.x * my_blocksize ,
                    left_top.y * my_blocksize ,
                    left_top.x * my_blocksize ,
                    group.get_height()*my_blocksize);

    QLine right_line(right_top.x * my_blocksize ,
                     right_top.y * my_blocksize ,
                     right_top.x * my_blocksize ,
                     group.get_height()*my_blocksize);

    QPen pen(Qt::DashLine);
    painter->setPen(pen);

    painter->drawLine(left_line);
    painter->drawLine(right_line);
}
