#include <cassert>
#include <QRect>
#include <QLine>
#include <QPen>
#include <QPalette>
#include <QIcon>
#include <QPoint>
#include <QDebug>
#include "qttetris.h"
#include "box.h"
#include "io_manager.h"

extern QColor trans_color(Tetris::BoxColor color);

QtTetris::QtTetris(QWidget* parent)
    : QWidget(parent),
      tetris(10, 18)
{
    IO_Manager::init();
    connect(IO_Manager::get(), &IO_Network::sig_Get, this, &QtTetris::onLines);
    groupwidget = new QtTetrisGroupWidget(tetris, this);
    nextwidget = new QtNextBoxWidget(tetris, this);

    timer.setInterval(1000);
    assert(!timer.isActive());
    connect(&timer, SIGNAL(timeout()), this, SLOT(time_up()));

    tetris.set_clock(Tetris::ClockDirection::AntiClock);
    resize((tetris.get_width() + left_size)*blocksize, tetris.get_height()*blocksize);

    groupwidget->setGeometry(0, 0, tetris.get_width()*blocksize, height());
    nextwidget->setGeometry(tetris.get_width()*blocksize + 5, 5, 3 * blocksize, 5 * blocksize);

    QIcon icon(":/png/icon.png");
    setWindowIcon(icon);
    //背景色
    //QPalette palette;
    //palette.setColor(QPalette::Background, Qt::cyan);
    //palette.setBrush(QPalette::Background, QBrush(QPixmap(":/background.png")));
    //setPalette(palette);
}

void QtTetris::update_widget()
{
    groupwidget->update();
    nextwidget->update();
}
void QtTetris::time_up()
{
    int droplines = 0;
    bool b = tetris.down(&droplines);

    if (droplines != 0)
    { IO_Manager::get()->send(droplines); }


    //update();
    update_widget();

    if(!b)
    { timer.stop(); }
}

void QtTetris::onLines(int n)
{
    while(n--)
    {
        tetris.up_one_line();
    }
    update_widget();
}

void QtTetris::keyPressEvent(QKeyEvent* e)
{
    if (!tetris.is_alive())
    {
        return;
    }

    const int key = e->key();
    // some logical wrong, but it works!
#ifndef NDEBUG

#else

    if (!timer.isActive())
    {
        if( key != Qt::Key_Enter
                && key != Qt::Key_Return
                && key != Qt::Key_Escape)
        { return; }
    }

#endif
    bool need_update = false;

    switch (key)
    {
    case Qt::Key_Up:
        need_update = tetris.turn();
        break;

    case Qt::Key_Left:
        need_update = tetris.move(Tetris::MoveDirection::Left);
        break;

    case Qt::Key_Right:
        need_update = tetris.move(Tetris::MoveDirection::Right);
        break;

    case Qt::Key_Down:
        need_update = tetris.move(Tetris::MoveDirection::Down);
        break;

    case Qt::Key_Space:
    {
        int droplines = 0;
        bool bb = tetris.down_to_bottom(&droplines);

        if (droplines != 0)
        { IO_Manager::get()->send(droplines); }

        update_widget();

        if (!bb)
        { timer.stop(); }
    }
    break;

    case Qt::Key_Enter:
    case Qt::Key_Return:
    case Qt::Key_Escape:
        if (timer.isActive())
        { timer.stop(); }
        else
        { timer.start(); }

        break;
    }

    if (need_update)
    {
        update_widget();
    }
}
