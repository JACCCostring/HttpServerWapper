#include "jsonentity.h"

jsonEntity::jsonEntity(QTcpSocket *negociator): instanceNegotiator(negociator)
{

}

void jsonEntity::execute(){ negotiate("json data, naaaa! no time to play with jsonDocument class xD"); }

void jsonEntity::negotiate(const QByteArray &message)
{
    instanceNegotiator->write(message);
}
