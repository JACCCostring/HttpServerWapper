#ifndef JSONENGINE_H
#define JSONENGINE_H

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject> //for json obj
#include <QVariant> //for variant type conversion
#include <QVector> //for QVector

class JsonEngine
{
public:
    explicit JsonEngine();
    //method to add objs to json map
    QByteArray toJson(const QString &, const QVariant &);
    QVariant fromJson(QByteArray, QString);
    //method to append serialized data to a vector
    void addJsonObj(const QString &, const QVariant &);
    //method to read all json obj from vector obj
    QByteArray readAllJson();
    void clearJsonVector();

private:
    QVector<QVariantMap> jsonVectorObj;
};

#endif // JSONENGINE_H
