#include "httpnonsecuresocket.h"

HttpNonSecureSocket::HttpNonSecureSocket(int sDescriptor, QObject *parent) :
    HttpSocket(parent),
    socketDescriptor(sDescriptor) //initializing socket desctiptor
{}

void HttpNonSecureSocket::handShakeInstance(QTcpSocket *instance, const QString &message)
{
    instance->write(message.toUtf8());
}

void HttpNonSecureSocket::run()
{
    //loggin
    qDebug()<<"threaded socket created and started";
    socketInstance = new QTcpSocket();

   if(! socketInstance->setSocketDescriptor(socketDescriptor)){
       //loggin
       qDebug()<<"socket descriptor error!";
   }
   //connecting signals when new data available and socket disconnected
   connect(socketInstance, &QTcpSocket::readyRead, this,
           &HttpNonSecureSocket::onNewDataReady, Qt::DirectConnection);

   connect(socketInstance, &QTcpSocket::disconnected, this,
           &HttpNonSecureSocket::onClosedConnection);
   //keeping loop for more incoming connections
   exec();
}

void HttpNonSecureSocket::onNewDataReady()
{
    //handshake back to client
    handShakeInstance(socketInstance, "HTTP/1.1 200 ok\r\n\r\n");
    //making HttpRequestValidator to validate request
    HttpRequestValidator requestValidator(socketInstance->readAll());
    //verifying if list has arguments before performance
    //that means if not arguments then dont preceed
    //this is because in some cases icon request automatically is sent without arguments
    if(requestValidator.getHttpListArgs().size() > 0){
        //loggin
        qDebug()<<"requesting";
        //creating objs in runtime
        std::shared_ptr<ClientImplementation> httpCImplementation(new HttpRequestHandler);
//        std::make_shared<HttpRequestHandler>();
        httpCImplementation->setHttpRequestValidator((//explicit cast to shared ptr
                                    std::shared_ptr<HttpRequestValidator>) &requestValidator);
        //setting negotiator
        httpCImplementation->setNegotiator((std::shared_ptr<QTcpSocket>) socketInstance);

        //executing
        httpCImplementation->execute();
        } //end of if statement
    //disconnecting client from server
    socketInstance->disconnectFromHost();
}

void HttpNonSecureSocket::onClosedConnection()
{
    //disconnecting and closing
    socketInstance->deleteLater();
    //exiting loop
    exit(0);
    //loggin
    qDebug()<< socketDescriptor << " disconnected";
}
