#include "clientimplementation.h"

ClientImplementation::ClientImplementation() {}

void ClientImplementation::setHttpRequestValidator(HttpRequestValidator *newParams)
{
    params = newParams;
}
