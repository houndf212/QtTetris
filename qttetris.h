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
protected:
    virtual void keyPressEvent(QKeyEvent*);
    Q_SLOT void time_up();
    Q_SLOT void onLines(int n);
private:
    QTimer timer;

    static const int blocksize = 40;
    static const int left_size = 4;

    Tetris::TetrisGroup tetris;
    QtTetrisGroupWidget* groupwidget;
    QtNextBoxWidget* nextwidget;

    void update_widget();
};

#endif // QTTETRISGROUP_H
