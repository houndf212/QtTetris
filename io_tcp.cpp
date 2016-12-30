#include "io_tcp.h"

const QByteArray IO_Tcp::heart_beat = "heart_beat";


IO_Tcp::IO_Tcp(QObject *parent)
    :IO_Network(parent)
{
    uuid = QUuid::createUuid();
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::readyRead, this, &IO_Tcp::onDataReady);
    connect(socket, &QTcpSocket::connected, this, &IO_Tcp::onConnected);
    connect(socket, &QTcpSocket::disconnected, this, &IO_Tcp::onClose);
}

void IO_Tcp::send(int n)
{
    if (socket->state() == QAbstractSocket::ConnectedState)
    {
        QJsonObject obj;
        obj.insert("uuid", uuid.toString());
        obj.insert("lines", n);
        QJsonDocument doc;
        doc.setObject(obj);
        QByteArray buffer = doc.toJson(QJsonDocument::Compact);
        socket->write(buffer);
    }
    else
    {
        qDebug() << "host disconnected! try to connect!";
        connectToHost();
    }
}

void IO_Tcp::onDataReady()
{
    QTcpSocket* s = qobject_cast<QTcpSocket*>(sender());
    QByteArray buffer = s->readAll();

    if (buffer == heart_beat)
    {
        qDebug() << "replay heart";
        socket->write(heart_beat);
        return;
    }

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

void IO_Tcp::onConnected()
{
    qDebug() << Q_FUNC_INFO;
}

void IO_Tcp::onClose()
{
    qDebug() << Q_FUNC_INFO;
    connectToHost();
}

void IO_Tcp::connectToHost()
{
    socket->connectToHost(server, port);
}
