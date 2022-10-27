#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H

#include <QtCore>

//abstract class
class HttpRequest
{
public:
    HttpRequest();

protected:
    //setters for httpCommand, body and httpListRoute not need to be virtual methods
    //because its preferible to set command, body and list of args no matter what
    void setHttpCommand(const QString &);
    void setHttpListArgs(const QString &);

    //variables
    std::map<QString, QString> request; //container to parse request
    QString httpCommand;
    QStringList httpListArgs;
};

#endif // HTTPREQUEST_H
