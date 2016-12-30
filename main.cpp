#include <QApplication>
#include <ctime>
#include <cstdlib>
#include "qttetris.h"
#include "io_tcp.h"

int main(int argc, char* argv[])
{
    std::srand(time(0));
    QApplication a(argc, argv);
    QtTetris w;
    w.show();
    return a.exec();
}
