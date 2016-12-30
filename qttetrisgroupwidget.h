#ifndef QTTETRISGROUPWIDGET_H
#define QTTETRISGROUPWIDGET_H

#include <QWidget>
#include "tetrisgroup.h"

class QPaintEvent;

class QtTetrisGroupWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QtTetrisGroupWidget(const Tetris::TetrisGroup& g, QWidget* parent = 0);

signals:

public slots:
protected:
    virtual void paintEvent(QPaintEvent*);
private:
    const Tetris::TetrisGroup& group;

    const int my_width;
    const int my_height;
    static const int my_blocksize = 20;
    void draw_group(QPainter*);
    void draw_curbox(QPainter*);
    void draw_alignlines(QPainter*);
    void draw_oneblock(QPainter* p, const Tetris::Dot& d, QColor color);
    Tetris::Dot find_most_left(const Tetris::Box* box) const;
};

#endif // QTTETRISGROUPWIDGET_H
