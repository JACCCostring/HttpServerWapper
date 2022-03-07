#include "httprequest.h"

HttpRequest::HttpRequest():
    httpCommand(QString()),
    httpListArgs(QStringList()) {}

void HttpRequest::setHttpCommand(const QString &cmd)
{   //assigning new command to httpCommand
    httpCommand = cmd;
}

void HttpRequest::setHttpListArgs(const QString &route)
{   //appending new route to list
    httpListArgs.append(route);
}
