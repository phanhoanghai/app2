#include <iostream>
#include "manager/appmanager.h"

int main(int argc, char *argv[])
{
    return AppManager::getInstance()->initApp(argc, argv);
}
