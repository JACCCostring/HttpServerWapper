#include "jsonengine.h"

JsonEngine::JsonEngine(){}

QByteArray JsonEngine::toJson(const QString &key, const QVariant &value)
{
    QJsonDocument jsonDoc;
    QJsonObject newJsonObj;
    //verifying type
    if(value.canConvert(QVariant::String))
    newJsonObj[key] = value.toString();

    if(value.canConvert(QVariant::Int))
    newJsonObj[key] = value.toString();

    if(value.canConvert(QVariant::Bool))
    newJsonObj[key] = value.toString();

    if(value.canConvert(QVariant::Double))
    newJsonObj[key] = value.toString();

    //setting raw obj to jsonDocument
    jsonDoc.setObject(newJsonObj);
    //returnning obj in  a json format
    return jsonDoc.toJson();
}

void JsonEngine::addJsonObj(const QString &key, const QVariant &value)
{
    QVariantMap jsonMap;
    jsonMap[key] = value;
    jsonVectorObj.append(jsonMap);
}

QByteArray JsonEngine::readAllJson()
{
    QJsonDocument jsonDoc;
    QJsonObject jsonObj;

    for(const auto &map: qAsConst(jsonVectorObj)){
        QString key = map.firstKey(); //retrieving key
        QVariant value =  map.first(); //retrieving value
        //verifying type
        if(value.canConvert(QVariant::String))
        jsonObj[key] = value.toString();

        if(value.canConvert(QVariant::Int))
        jsonObj[key] = value.toString();

        if(value.canConvert(QVariant::Bool))
        jsonObj[key] = value.toString();

        if(value.canConvert(QVariant::Double))
        jsonObj[key] = value.toString();
    }
    //setting raw obj to jsonDocument
    jsonDoc.setObject(jsonObj);
    //returnning obj in  a json format
    return jsonDoc.toJson();
}

