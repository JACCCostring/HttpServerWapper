#include "HttpRequestHandler.h"

HttpRequestHandler::HttpRequestHandler(){}

void HttpRequestHandler::execute(){
    //miking shure its a GET request
    if(params->command("GET")){
    //making sure add argument is not valid, in a GET request
    if(params->getArgs(0).startsWith("add")){
        if(params->command("GET"))
            negotiate(jsonEngine->toJson("error", "most be a POST request"));
        }//end of verifying add argument
    if(params->getArgs(0).startsWith("calculate")){
        if(params->validateArgs(1))
        negotiate(jsonEngine->toJson("calc", params->getArgs(1)));
        else
            negotiate(jsonEngine->toJson("exeception", "must specify arguments/params Ex: Arg/Param/"));
    }
    //search
    if(params->getArgs(0).startsWith("search")){
        //verifying that has more then 1 argument
        if(params->validateArgs(1))
        negotiate(jsonEngine->toJson("name", params->getArgs(1)));
    }//end of search argument
    //append
    if(params->getArgs(0).startsWith("append")){
            if(params->validateArgs(1))
            if(params->validateArgs(2))
            if(params->validateArgs(3))
            if(params->validateArgs(4))
            if(params->validateArgs(5))
            if(params->validateArgs(6))
            if(params->validateArgs(7))
            {
                //populating data to json obj
                jsonEngine->addJsonObj("name", params->getArgs(2));
                jsonEngine->addJsonObj("surname", params->getArgs(3));
                jsonEngine->addJsonObj("address", params->getArgs(4));
                jsonEngine->addJsonObj("state", params->getArgs(5));
                jsonEngine->addJsonObj("marital state", params->getArgs(6));
                jsonEngine->addJsonObj("area code", params->getArgs(7).toInt());
                //retrieving json and negotiating it
                negotiate(jsonEngine->readAllJson());
    }
    }//end of append
} //end of GET
} //end of execute method

void HttpRequestHandler::negotiate(const QByteArray &message)
{
    negotiatorInstance->write(message);
}
