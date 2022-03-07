#include "jsonentity.h"

jsonEntity::jsonEntity()
{

}

void jsonEntity::execute(){
    if(params->getHttpListArgs().at(0).startsWith("add")){ negotiate("Adding user"); }
    else if(params->getHttpListArgs().at(0).startsWith("delete")){ negotiate("Deleting user"); }
    else if(params->getHttpListArgs().at(0).startsWith("update")){ negotiate("Updating user"); }
    else if(params->getHttpListArgs().at(0).startsWith("search")){ negotiate("Searching user"); }
}

void jsonEntity::negotiate(const QByteArray &message)
{
    negotiatorInstance->write(message);
}
