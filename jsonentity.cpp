#include "jsonentity.h"

jsonEntity::jsonEntity(QTcpSocket *negociator): instanceNegotiator(negociator)
{

}

jsonEntity::~jsonEntity()
{
    if(params)
        delete params;

    if(instanceNegotiator)
    instanceNegotiator->deleteLater();
}

void jsonEntity::execute(){
    if(params->getHttpListArgs().at(0).startsWith("add")){ negotiate("Adding user"); }
    else if(params->getHttpListArgs().at(0).startsWith("delete")){ negotiate("Deleting user"); }
    else if(params->getHttpListArgs().at(0).startsWith("update")){ negotiate("Updating user"); }
    else if(params->getHttpListArgs().at(0).startsWith("search")){ negotiate("Searching user"); }
}

void jsonEntity::negotiate(const QByteArray &message)
{
    instanceNegotiator->write(message);
}
