#ifndef HTTPREQUESTHANDLER_H
#define HTTPREQUESTHANDLER_H

#include "clientimplementation.h"
#include <QTcpSocket>

class HttpRequestHandler : public ClientImplementation
{
public: //this is class inherit from ClientImplementation
        //and will implement json functionalities
    HttpRequestHandler();
    //override method
    void execute() override;

private:
    //method to send message back to negotiator
    void negotiate(const QByteArray &);
};

#endif // HTTPREQUESTHANDLER_H
