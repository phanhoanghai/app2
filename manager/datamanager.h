#ifndef __DATAMANAGER_H__
#define __DATAMANAGER_H__

#include <QString>
#include <QJsonArray>
#include "data/employeemodel.h"

class DataManager
{
private:
    DataManager();

public:
    static DataManager* getInstance();

public:
    QJsonArray convertTextToJson(QString& text);
    QString convertJsonToText(QJsonArray& json);
    void convertDataToModel(QJsonArray& data, EmployeeModel& model);
};

#endif // __DATAMANAGER_H__
