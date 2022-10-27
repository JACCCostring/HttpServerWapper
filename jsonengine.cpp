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
    newJsonObj[key] = value.toInt();

    if(value.canConvert(QVariant::Bool))
    newJsonObj[key] = value.toBool();

    if(value.canConvert(QVariant::Double))
    newJsonObj[key] = value.toDouble();

    //setting raw obj to jsonDocument
    jsonDoc.setObject(newJsonObj);
    //returnning obj in  a json format
    return jsonDoc.toJson();
}

QVariant JsonEngine::fromJson(QByteArray json, QString key)
{
    //getting json from request
    QJsonDocument jsonDoc = QJsonDocument::fromJson(json);
    //getting obj from QJsonDocument
    QJsonObject jsonObj = jsonDoc.object();
    //returning value from jsonObj
    return jsonObj[key].toVariant();
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

void JsonEngine::clearJsonVector()
{
    jsonVectorObj.clear();
}

