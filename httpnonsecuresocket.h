#ifndef HTTPNONSECURESOCKET_H
#define HTTPNONSECURESOCKET_H

#include "httprequestvalidator.h"
#include "httpsocket.h"
#include "HttpRequestHandler.h"

#include <QObject>

class HttpNonSecureSocket : public HttpSocket
{
    Q_OBJECT
public:
    explicit HttpNonSecureSocket(int sDescriptor, QObject *parent = nullptr);
    //method to make handshake between client and server
    void handShakeInstance(QTcpSocket *, const QString &);
// HttpSocket interface
protected:
    void run() override;

protected slots:
    void onNewDataReady() override;
    void onClosedConnection() override;

private:
    QTcpSocket *socketInstance;
    int socketDescriptor;
};

#endif // HTTPNONSECURESOCKET_H
