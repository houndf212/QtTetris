#ifndef IO_UDP_H
#define IO_UDP_H
#include <QtNetwork>
#include "io_network.h"

class IO_Udp : public IO_Network
{
    Q_OBJECT
public:
    explicit IO_Udp(QObject* parent=0);
    virtual void send(int n) override;
    virtual void connectToHost() override {}
private:
    Q_SLOT void onDataReady();
    QUdpSocket *socket;
    QUuid uuid;
};

#endif // IO_UDP_H
