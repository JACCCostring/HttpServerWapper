#include "clientimplementation.h"

ClientImplementation::ClientImplementation() {
    //initialized jsonEngine at declaration
    jsonEngine = std::make_shared<JsonEngine>();
}

void ClientImplementation::setHttpRequestValidator(std::shared_ptr<HttpRequestValidator> newParams)
{
    params = newParams;
}

void ClientImplementation::setNegotiator(std::shared_ptr<QTcpSocket> newNegociator)
{
    negotiatorInstance = newNegociator;
}
