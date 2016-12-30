#ifndef IO_TCP_H
#define IO_TCP_H
#include <QTcpSocket>
#include "io_network.h"

class IO_Tcp : public IO_Network
{
    Q_OBJECT
public:
    explicit IO_Tcp(QObject *parent=0);
    virtual void send(int n) override;
    virtual void connectToHost() override;
private:
    Q_SLOT void onDataReady();
    Q_SLOT void onConnected();
    Q_SLOT void onClose();

private:
    QTcpSocket *socket;
    QUuid uuid;

    static const QByteArray heart_beat;
};

#endif // IO_TCP_H
