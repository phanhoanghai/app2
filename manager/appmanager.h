#ifndef APPMANAGER_H
#define APPMANAGER_H

#include "data/employeemodel.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

class AppManager
{
private:
     AppManager();

public:
    static AppManager* getInstance();

public:
    bool initApp(int argc, char *argv[]);
    bool initView(int argc, char *argv[]);
    bool initData();
    bool initServer();

public:
    void requestTest();

private:
    EmployeeModel m_appModel;
};

#endif // APPMANAGER_H
