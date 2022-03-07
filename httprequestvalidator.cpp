#include "httprequestvalidator.h"

HttpRequestValidator::HttpRequestValidator(const QByteArray &rawRequest)
{
    //retrieving const QByteArray to a QString to modify it
    QString toValidate = rawRequest;
    //splitting by /
    QStringList splittedRawRequest = toValidate.split("/");
    //making sure data goes to the right place
    //retrieving num of arguments in request
    int argsNum = getArgsNum(splittedRawRequest);
    //retrieving command before loop since command always will be the 1st element in request
    setHttpCommand(splittedRawRequest.at(0));
    //looping throught the hole list and retrieve arguments
    for(int i = 1; i < argsNum; i++){
        setHttpListArgs(splittedRawRequest.at(i));
    }
}

int HttpRequestValidator::getArgsNum(const QStringList &list)
{
    int argsNum = 0; //counter init.. to 0
    for(const QString &lst: qAsConst(list)){
        if(lst.contains("HTTP")){ break; } //if HTTP tag is found then increment break
         argsNum++; //counting every element/args in list
        }
    //returning number of args found in list
    return argsNum;
}

QString HttpRequestValidator::getHttpCommand()
{ //method override
    return httpCommand;
}

QStringList HttpRequestValidator::getHttpListArgs()
{   //method override
    return httpListArgs;
}
