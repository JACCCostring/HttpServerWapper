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
    void setHttpRequestValidator(HttpRequestValidator *);

protected: //the deletion of this obj will be at the client implementation destructor
    HttpRequestValidator *params;
};

#endif // CLIENTIMPLEMENTATION_H
