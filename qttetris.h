#ifndef QTTETRIS_H
#define QTTETRIS_H

#include <QWidget>
#include <QTimer>
#include <QKeyEvent>
#include <QPainter>
#include <QColor>
#include <QDebug>
#include "define.h"
#include "tetrisgroup.h"
#include "qtnextboxwidget.h"
#include "qttetrisgroupwidget.h"

class QtTetris : public QWidget
{
    Q_OBJECT
public:
    QtTetris(QWidget* parent = 0);
    ~QtTetris();

protected:
    virtual void keyPressEvent(QKeyEvent*);
public slots:
    void time_up();

private:
    void set_cur_drop_lines(int lines);
    QTimer timer;
    int cur_drop_lines;
    int drop_lines_count;
    static const int blocksize = 40;
    static const int left_size = 4;

    Tetris::TetrisGroup tetris;
    QtTetrisGroupWidget* groupwidget;
    QtNextBoxWidget* nextwidget;

    void update_widget();
};

inline void QtTetris::set_cur_drop_lines(int lines)
{
    cur_drop_lines = lines;

    drop_lines_count += lines;
    qDebug() << "cur is " << lines;
    qDebug() << "all is " << drop_lines_count;
}
#endif // QTTETRISGROUP_H
