#ifndef QMLINTERFACE_H
#define QMLINTERFACE_H

#include <QObject>

class QMLInterface : public QObject
{
    Q_OBJECT
public:
    explicit QMLInterface (QObject* parent = 0) : QObject(parent) {}

public:
    Q_INVOKABLE void test();
};

#endif // QMLINTERFACE_H
