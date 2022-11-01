#include "qmlinterface.h"
#include "manager/appmanager.h"

void QMLInterface::test()
{
    AppManager::getInstance()->requestTest();
}
