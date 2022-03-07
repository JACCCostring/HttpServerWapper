#include "httpserver.h"
#include <QDebug>

HttpServer::HttpServer(QObject *parent) :QTcpServer(parent)
{}

void HttpServer::startServer(qint16 port)
{
    if(! this->isListening()) this->listen(QHostAddress::Any, port);
    qDebug()<<"Server is Listening ....";
}

void HttpServer::incomingConnection(qintptr descriptor)
{
    //creating abstract http socket with a new HttpNonSecureSocket instance
    HttpSocket *httpThreadedSocket = new HttpNonSecureSocket(descriptor, this);
    qDebug()<<descriptor<< " has been connected";
    //connecting signal when threaded obj terminate executing
    connect(httpThreadedSocket, &QThread::finished, this, &QThread::deleteLater);
    //starting threaded obj
    httpThreadedSocket->start();
}
