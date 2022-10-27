#include "httprequest.h"

HttpRequest::HttpRequest():
    httpCommand(QString()),
    httpListArgs(QStringList()) {}

void HttpRequest::setHttpCommand(const QString &cmd)
{   //assigning new command to httpCommand
    httpCommand = cmd;
}

void HttpRequest::setHttpListArgs(const QString &arg)
{   //appending new route to list
    httpListArgs.append(arg);
}

