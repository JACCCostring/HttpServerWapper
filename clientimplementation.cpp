#include "clientimplementation.h"

ClientImplementation::ClientImplementation() {}

void ClientImplementation::setHttpRequestValidator(std::shared_ptr<HttpRequestValidator> newParams)
{
    params = newParams;
}

void ClientImplementation::setNegotiator(std::shared_ptr<QTcpSocket> newNegociator)
{
    negotiatorInstance = newNegociator;
}
