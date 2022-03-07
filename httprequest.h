#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H
#include <QtCore>
//abstract class
class HttpRequest
{
public:
    HttpRequest();

public:
    //setters for httpCommand and httpListRoute not need to be virtual methods
    //because its preferible to set command and list of args no matter what
    void setHttpCommand(const QString &);
    void setHttpListArgs(const QString &);

protected:
    QString httpCommand;
    QStringList httpListArgs;
};

#endif // HTTPREQUEST_H
