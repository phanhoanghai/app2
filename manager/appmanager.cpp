#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "appmanager.h"
#include "data/employeemodel.h"
#include "serverlistenner/readsharemem.h"
#include "manager/datamanager.h"
#include "serverlistenner/msgqueue.h"
#include "interface/qmlinterface.h"
#include "util/MsgHelper.h"

using namespace std;
static AppManager* m_instance;

AppManager::AppManager()
{
}

AppManager *AppManager::getInstance()
{
    if (m_instance == nullptr) {
        m_instance = new AppManager();
    }
    return m_instance;
}

bool AppManager::initApp(int argc, char *argv[])
{
    initData();
    initView(argc, argv);
    return true;
}

bool AppManager::initView(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    qmlRegisterType<QMLInterface>("com.myapp", 1, 0, "QmlInterface");

    QQmlApplicationEngine engine;
    QQmlContext* ctxt = engine.rootContext();
    ctxt->setContextProperty("myModel", &m_appModel);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

bool AppManager::initData()
{
    QString textData = QString::fromStdString(ReadShareMem::getInstance()->getSharemem());
    QJsonArray jsonData = DataManager::getInstance()->convertTextToJson(textData);
    DataManager::getInstance()->convertDataToModel(jsonData, m_appModel);
    return true;
}

bool AppManager::initServer()
{
    MsgQueue::getInstance()->initMsgQueue();
    return true;
}

void AppManager::requestTest()
{
    MsgQueue::getInstance()->sendingMsg(messagere_refresh());
}
