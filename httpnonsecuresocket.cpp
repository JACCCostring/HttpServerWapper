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
    qDebug()<<"Threaded socket started";
    socketInstance = new QTcpSocket;

   if(! socketInstance->setSocketDescriptor(socketDescriptor)){
       qDebug()<<"Socket desctriptor err";
   }
   //connecting signals when new data available and socket disconnected
   connect(socketInstance, &QTcpSocket::readyRead, this,
           &HttpNonSecureSocket::onNewDataReady, Qt::DirectConnection);

   connect(socketInstance, &QTcpSocket::disconnected, this,
           &HttpNonSecureSocket::onClosedConnection, Qt::DirectConnection);
   //keeping loop for more incoming connections
   exec();
}

void HttpNonSecureSocket::onNewDataReady()
{
    //handshake back to client
    handShakeInstance(socketInstance, "HTTP/1.1 200 ok\r\n\r\n");
    //making HttpRequestValidator to validate request
    HttpRequestValidator requestValidator(socketInstance->readAll());
    //verifying http commands
    //if request is a GET
    if(requestValidator.getHttpCommand().startsWith("GET")){
        qDebug()<<"Get Request";
        //verifying if list has arguments before performance
        //that means if not arguments then dont preceed
        //this is because in some cases icon request automatically is sent without arguments
        if(requestValidator.getHttpListArgs().size() > 0){
        //creating objs in runtime
        ClientImplementation *httpCImplementation = new jsonEntity;
        httpCImplementation->setHttpRequestValidator((//explicit cast to shared ptr
                                                         std::shared_ptr<HttpRequestValidator>) &requestValidator);
        //setting negotiator
        httpCImplementation->setNegotiator((std::shared_ptr<QTcpSocket>) socketInstance);
        //executing
        httpCImplementation->execute();
        } //end of if statement
    }
    //if request is a POST
    else if(requestValidator.getHttpCommand().startsWith("POST")){
        qDebug()<<"POST Request";
        //verifying if list has arguments before performance
        //that means if not arguments then dont preceed
        //this is because in some cases icon request automatically is sent without arguments
        if(requestValidator.getHttpListArgs().size() > 0){
        //creating objs in runtime
        //ClientImplementation *httpCImplementation = new jsonEntity(socketInstance);
        //httpCImplementation->setHttpRequestValidator(&requestValidator);
        //httpCImplementation->execute();
        } //end of if statement
    }
    //disconnecting client from server
    socketInstance->disconnectFromHost();
}

void HttpNonSecureSocket::onClosedConnection()
{
    //disconnecting and closing
    socketInstance->deleteLater();
    //exiting loop
    //exit(0);
    qDebug()<<socketDescriptor << " Disconnected";
}
