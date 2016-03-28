#include <QPainter>
#include "box.h"
#include "qtnextboxwidget.h"

extern QColor trans_color(Tetris::BoxColor::Color color);

QtNextBoxWidget::QtNextBoxWidget(const Tetris::TetrisGroup& g, QWidget* parent) :
    QWidget(parent),
    group(g)
{
}

void QtNextBoxWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setWindow(0, 0, my_width, my_height);
    draw_nextbox(&painter);
}

void QtNextBoxWidget::draw_nextbox(QPainter* painter)
{
    const Tetris::Box* box = group.get_next_box();
    // because of Koening , so "Tetris::" do not needed
    Tetris::Dot d = /*Tetris::*/find_most_left(box);
    //这里赋值0是很有道理的，因为只需要左移动，不需要下移动
    d.y = 0;

    for (const Tetris::Dot* p = box->begin(); p != box->end(); ++p)
    {
        draw_oneblock(painter, *p - d, trans_color(box->get_color()));
    }
}

void QtNextBoxWidget::draw_oneblock(QPainter* p, const Tetris::Dot& d, QColor color)
{
    assert(d.x < QtNextBoxWidget::width_num);
    assert(d.y < QtNextBoxWidget::height_num);
    const int block_alig = 0;

    //p->setPen(color);
    p->setBrush(color);
    const QRect rect(d.x * my_blocksize + block_alig,
                     d.y * my_blocksize + block_alig,
                     my_blocksize - 2 * block_alig,
                     my_blocksize - 2 * block_alig);
    p->drawRect(rect);
}
