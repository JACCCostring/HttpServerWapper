#ifndef JSONENTITY_H
#define JSONENTITY_H

#include "clientimplementation.h"
#include <QTcpSocket>

class jsonEntity : public ClientImplementation
{
public: //this is class inherit from ClientImplementation
        //and will implement json functionalities
    jsonEntity();
    //override method
    void execute() override;

private:
    //method to send message back to negotiator
    void negotiate(const QByteArray &);
};

#endif // JSONENTITY_H
