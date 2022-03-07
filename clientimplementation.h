#ifndef CLIENTIMPLEMENTATION_H
#define CLIENTIMPLEMENTATION_H

#include "httprequestvalidator.h"

class ClientImplementation
{
public: //this is a class interface to allow inheritance and creation of new classes
    ClientImplementation();
    //virtual method to override on each subclass when need it
    virtual void execute() = 0;
    //method to set httpRequestValidator
    void setHttpRequestValidator(std::shared_ptr<HttpRequestValidator>);
    void setNegotiator(std::shared_ptr<QTcpSocket>);

protected: //shared ptr to allow assignation =
    std::shared_ptr<HttpRequestValidator> params;
    std::shared_ptr<QTcpSocket> negotiatorInstance;
};

#endif // CLIENTIMPLEMENTATION_H
