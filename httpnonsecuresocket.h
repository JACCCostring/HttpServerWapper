#ifndef HTTPNONSECURESOCKET_H
#define HTTPNONSECURESOCKET_H

#include "httprequestvalidator.h"
#include "httpsocket.h"
#include "httprequest.h"
#include "jsonentity.h"
#include <QObject>

class HttpNonSecureSocket : public HttpSocket
{
    Q_OBJECT
public:
    explicit HttpNonSecureSocket(int sDescriptor, QObject *parent = nullptr);
    //method to make handshake between client and server
    void handShakeInstance(QTcpSocket *, const QString &);

protected:
    void run() override;

    // HttpSocket interface
protected slots:
    void onNewDataReady() override;
    void onClosedConnection() override;

private:
    QTcpSocket *socketInstance;
    int socketDescriptor;
};

#endif // HTTPNONSECURESOCKET_H
