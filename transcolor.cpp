#include <QColor>
#include "define.h"

QColor trans_color(Tetris::BoxColor::Color color)
{
    QColor col;

    switch (color)
    {
    case Tetris::BoxColor::Square:
        col = Qt::yellow;
        break;

    case Tetris::BoxColor::Three:
    case Tetris::BoxColor::Four:
    case Tetris::BoxColor::Five:
        col = Qt::blue;
        break;

    case Tetris::BoxColor::Seven:
    case Tetris::BoxColor::SevenReverse:
        col = Qt::red;
        break;

    case Tetris::BoxColor::Z:
    case Tetris::BoxColor::ZReverse:
        col = Qt::green;
        break;

    case Tetris::BoxColor::Convex:
    case Tetris::BoxColor::Cross:
        col = Qt::darkRed;
        break;

    case Tetris::BoxColor::One:
        col = Qt::magenta;
        break;

    default:
        col = Qt::magenta;
    }

    return col;
}
