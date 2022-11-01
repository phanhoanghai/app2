#include "datamanager.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <string>
#include "util/AppDefine.h"
#include <math.h>

using namespace std;
static DataManager* m_instance;

DataManager::DataManager()
{

}

DataManager *DataManager::getInstance()
{
    if (m_instance == nullptr) {
        m_instance = new DataManager();
    }
    return m_instance;
}

QJsonArray DataManager::convertTextToJson(QString& text)
{
    QJsonArray jsonData;
    auto json_doc = QJsonDocument::fromJson(text.toUtf8());

    QJsonArray jArr = json_doc.array();
    QJsonValue val;

    for (auto jsonObj : jArr) {
        QJsonObject obj;
        for (int i = 0; i < 7; i++) {
            val = jsonObj.toObject().value(json_defined_datas[i].c_str());
            obj.insert(json_defined_datas[i].c_str(), jsonObj.toObject().value(json_defined_datas[i].c_str()));
        }
        jsonData.append(obj);
    }

    return jsonData;
}

QString DataManager::convertJsonToText(QJsonArray& json)
{
    QJsonDocument doc;
    doc.setArray(json);
    QString stringdata(doc.toJson());
    return stringdata;
}

void DataManager::convertDataToModel(QJsonArray& data, EmployeeModel& model)
{
    foreach (const QJsonValue& value, data) {
        QJsonObject obj = value.toObject();
        int index = obj["index"].toInt();
        QString name = obj["name"].toString();
        int assem = obj["assem"].toInt();
        int cplus = obj["cplus"].toInt();
        int js = obj["js"].toInt();
        int qml = obj["qml"].toInt();
        int openGL = obj["openGL"].toInt();
        float average = ((float)assem + (float)cplus + (float)js + (float)qml + (float)openGL) / 5.0f;
        model.addEmployee(Employee(index, name.toStdString().c_str(), average, assem, cplus, js, qml, openGL));
    }
}

