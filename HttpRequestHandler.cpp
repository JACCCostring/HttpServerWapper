#include "HttpRequestHandler.h"

HttpRequestHandler::HttpRequestHandler(){}

struct{
float x;
float y;    
} Coords;

bool findCoords(Coords coords){
//     find coords algotithm 
//     .......
//         ......
//     if(coords exist){
        moveRobot(coords);
        return true;   
     }

return false;
}

void HttpRequestHandler::execute(){
    //miking shure its a GET request
    if(params->getRequest()["Method"].startsWith("GET")){
         if(params->getRequest()["Route"].startsWith("coords"))){
            double x = jsonEngine->fromJson(params->getRequest()["Body"].toUtf8(), "coord-x").toDouble(); 
            double y = jsonEngine->fromJson(params->getRequest()["Body"].toUtf8(), "coord-y").toDouble();
            if(findCoords(Coords{x, y})){
            jsonEngine->addJsonObj("coord x found", x);
            jsonEngine->addJsonObj("coord y found", y);
            negociatorInstance(jsonEngine->readAllJson());
            }
                
         }   
} //end of GET
} //end of execute method

void HttpRequestHandler::negotiate(const QByteArray &message)
{
    negotiatorInstance->write(message);
}
