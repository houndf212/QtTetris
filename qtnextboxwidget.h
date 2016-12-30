#ifndef QTNEXTBOXWIDGET_H
#define QTNEXTBOXWIDGET_H

#include <QWidget>
#include "tetrisgroup.h"
class QPaintEvent;

class QtNextBoxWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QtNextBoxWidget(const Tetris::TetrisGroup& g, QWidget* parent = 0);

signals:

public slots:
protected:
    void paintEvent(QPaintEvent*);
private:
    const Tetris::TetrisGroup& group;
    static const int my_blocksize = 20;
    static const int width_num = 3;
    static const int height_num = 5;
    static const int my_width = width_num* my_blocksize;
    static const int my_height = height_num* my_blocksize;

    void draw_nextbox(QPainter*);
    void draw_oneblock(QPainter* p, const Tetris::Dot& d, QColor color);

};

#endif // QTNEXTBOXWIDGET_H
