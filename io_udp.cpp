#include "io_udp.h"

IO_Udp::IO_Udp(QObject *parent)
    :IO_Network(parent)
{
    uuid = QUuid::createUuid();
    socket = new QUdpSocket(this);
    connect(socket, &QUdpSocket::readyRead, this, &IO_Udp::onDataReady);
    bool b = socket->bind(port);
    if (!b)
        qApp->exit(-1);
}

void IO_Udp::send(int n)
{
    QJsonObject obj;
    obj.insert("uuid", uuid.toString());
    obj.insert("lines", n);
    QJsonDocument doc;
    doc.setObject(obj);
    QByteArray buffer = doc.toJson(QJsonDocument::Compact);
    socket->writeDatagram(buffer, QHostAddress(server), port);
}

void IO_Udp::onDataReady()
{
    QHostAddress addr;
    quint16 lport=0;
    QByteArray buffer(socket->pendingDatagramSize(), 0);
    socket->readDatagram(buffer.data(), buffer.size(), &addr, &lport);

    if (lport != port)
        return;

    qDebug() <<addr;

    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(buffer, &err);
    if (err.error != QJsonParseError::NoError)
        return;

    QJsonObject obj = doc.object();
    QUuid luuid(obj.value("uuid").toString());
    if (luuid == uuid)
        return;

    int lines = obj.value("lines").toInt(0);
    if (lines!=0)
    { Q_EMIT sig_Get(lines); }
}
