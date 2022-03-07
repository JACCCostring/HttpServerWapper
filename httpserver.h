#ifndef HTTPSERVER_H
#define HTTPSERVER_H

#include <QTcpServer>
#include <QObject>
#include "httpnonsecuresocket.h"

class HttpServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit HttpServer(QObject *parent = nullptr);
    //start server method
    void startServer(qint16);

protected:
    //overriding method QTcpServer class
    void incomingConnection(qintptr) override;
};

#endif // HTTPSERVER_H
