#include "io_manager.h"
#include "io_tcp.h"
#include "io_udp.h"
#include <QSettings>

const QString IO_Manager::kFileName = "settings.ini";
std::unique_ptr<IO_Network> IO_Manager::io;

void IO_Manager::init()
{
    QSettings s(kFileName, QSettings::IniFormat);
    int type = s.value("app/type", 1).toInt();
    QString server = s.value("app/server").toString();
    quint16 port = s.value("app/port").toUInt();

    switch(type)
    {
    case 0:
        io.reset(new IO_Udp);
        break;
    case 1:
    default:
        io.reset(new IO_Tcp);
    }
    io->setServer(server);
    io->setPort(port);

    io->connectToHost();
}

IO_Network *IO_Manager::get()
{
    Q_ASSERT(io != nullptr);
    return io.get();
}
