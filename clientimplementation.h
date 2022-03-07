#ifndef CLIENTIMPLEMENTATION_H
#define CLIENTIMPLEMENTATION_H

#include "httprequest.h"

class ClientImplementation : public HttpRequest
{
public: //this is a class interface to allow inheritance and creation of new classes
    ClientImplementation();
    //virtual method to override on each subclass when need it
    virtual void execute() = 0;
};

#endif // CLIENTIMPLEMENTATION_H
