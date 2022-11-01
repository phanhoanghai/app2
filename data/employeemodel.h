#ifndef EMPLOYEEMODEL_H
#define EMPLOYEEMODEL_H

#include <QAbstractListModel>
#include "employee.h"

class EmployeeModel : public QAbstractListModel
{
    Q_OBJECT
public:
    EmployeeModel(QObject* parent = 0);

public:
    enum EmployeeRoles {
        e_index = Qt::UserRole + 1,
        NameRole,
        averageRole,
        assem,
        cplus,
        js,
        qml,
        openGL
    };

public:
    void addEmployee(const Employee& employee);
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

    Q_INVOKABLE QVariantMap get(int row) const;

protected:
    QHash<int, QByteArray> roleNames() const;

private:
    QList<Employee> m_employees;
};

#endif // EMPLOYEEMODEL_H
