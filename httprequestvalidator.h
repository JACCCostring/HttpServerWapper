#ifndef HTTPREQUESTVALIDATOR_H
#define HTTPREQUESTVALIDATOR_H

#include <QtCore>
#include "httprequest.h"

class HttpRequestValidator: public HttpRequest
{
public:
    HttpRequestValidator(const QByteArray &);
    //method to count number of arguments in a list of string
    int getArgsNum(const QStringList &);
    //methods to retrieve data from inherited members
    QString getHttpCommand();
    QStringList getHttpListArgs();
};

#endif // HTTPREQUESTVALIDATOR_H
