#ifndef IO_NETWORK_H
#define IO_NETWORK_H
#include <QtCore>

class IO_Network : public QObject
{
    Q_OBJECT
public:
    explicit IO_Network(QObject *parent=0) : QObject(parent) {}
    Q_SIGNAL void sig_Get(int n);
    virtual void send(int n) = 0;
    virtual void connectToHost() = 0;

    void setServer(const QString& s) { server=s; }
    void setPort(quint16 p) { port = p; }
protected:
    QString server;
    quint16 port;
};

#endif // IO_NETWORK_H
