#ifndef HTTPREQUESTVALIDATOR_H
#define HTTPREQUESTVALIDATOR_H

#include <QtCore>
#include <QTcpSocket>

#include "httprequest.h"

class HttpRequestValidator: public HttpRequest
{
public:
    HttpRequestValidator(const QByteArray &);
    //methods to retrieve HTTP command used
    bool command(const QString command) const;
    //method to return an especific argument
    QString getArgs(int numArg) const;
    //method to validate if argument exist
    bool validateArgs(int) const;
    //methods to retrieve all arguments used
    QStringList getHttpListArgs();
    //get container of key value pair
    std::map<QString, QString> getRequest();

private:
    //method to count number of arguments in a list of string
    int getArgsNum(const QStringList &);
    //method to find json body
    void parseBody(const QByteArray &);
    //parse request
    void parseRequest(const QByteArray &);
    //parse only method, path and version
    void getMethodPathVersion(const QByteArray &);
};

#endif // HTTPREQUESTVALIDATOR_H
