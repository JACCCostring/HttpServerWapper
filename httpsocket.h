#ifndef HTTPSOCKET_H
#define HTTPSOCKET_H

#include <QThread>
#include <QTcpSocket>
#include <QObject>

class HttpSocket : public QThread
{
    Q_OBJECT
public:
    explicit HttpSocket(QObject *parent = nullptr);

protected slots:
    virtual void onNewDataReady() = 0;
    virtual void onClosedConnection() = 0;
};

#endif // HTTPSOCKET_H
