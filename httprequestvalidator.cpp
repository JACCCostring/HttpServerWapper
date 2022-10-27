#include "httprequestvalidator.h"

HttpRequestValidator::HttpRequestValidator(const QByteArray &rawRequest)
{
    //retrieving const QByteArray to a QString to parse it
    QString forArgs = rawRequest;

    /*
    NOTE: All the parsing apart from parseRequest() invoke, it's purpuse
    is to allow access to request route e.x: /var/file/index.html
                                                    0    1     2 = route 1 / route 2 and route 3
    but anyway when parseRequest() is invoked route is also parsed but in one line
    no divided by number of route
    */

    //parsing http request for method, route, version, key pair values and body
    parseRequest(rawRequest);
    //splitting by /
    QStringList splittedRawRequest = forArgs.split("/");
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

    for(const QString &lst: qAsConst(list))
    {
        if(lst.contains("HTTP")) { break; } //if HTTP tag is found then break
         argsNum++; //counting every element/args in list
        }
    //returning number of args found in list
    return argsNum;
}

void HttpRequestValidator::parseBody(const QByteArray &rawRequest)
{
        QString findRequestBody = rawRequest;
        //split string by \r\n\r\n that is at the end of the http request
        QStringList splittedReq = findRequestBody.split("\r\n\r\n");
        //retrieving last string - 1 that's the body position in the htttp request
        request["Body"] = splittedReq[splittedReq.size()-1];
}

bool HttpRequestValidator::command(const QString command) const
{
    return httpCommand.startsWith(command);
}

QStringList HttpRequestValidator::getHttpListArgs()
{
    return httpListArgs;
}

QString HttpRequestValidator::getArgs(int numArg) const
{
    return httpListArgs.at(numArg);
}

bool HttpRequestValidator::validateArgs(int numArg) const
{
    return httpListArgs.size() > numArg;
}

std::map<QString, QString> HttpRequestValidator::getRequest()
{
    return request;
}

void HttpRequestValidator::parseRequest(const QByteArray &req)
{
    QString splitReq = req; //copying to modified

    getMethodPathVersion(req); //parsing method, route and version 1st
    parseBody(req); //parsing body of request

    QStringList lst = splitReq.split("\n"); //split by \n

    for(const auto &l: qAsConst(lst)){ //looping throug list
        if(l.contains(":"))
        { //if its a pair
            QStringList r = l.split(":"); //then split the pair
            request[r[0]] = {{r[1]}}; //assigning key and value to a map container
        }
    }
}

void HttpRequestValidator::getMethodPathVersion(const QByteArray &req)
{
    QString dataSplitted = req;
    QStringList list = dataSplitted.split("\n");

    for(const auto &lst: qAsConst(list)){
        QStringList lstSplitted = lst.split(" ");

        request["Method"] = lstSplitted[0].trimmed(); //appending value without character /n
        request["Route"] = lstSplitted[1].trimmed();
        request["Version"] = lstSplitted[2].trimmed();
        break; //break to avoid overflow
    }
}
