#include "employeemodel.h"
#include "qdebug.h"

EmployeeModel::EmployeeModel(QObject* parent)
    : QAbstractListModel(parent) {

}

void EmployeeModel::addEmployee(const Employee& employee) {
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_employees << employee;
    endInsertRows();
}

int EmployeeModel::rowCount(const QModelIndex& parent) const {
    Q_UNUSED(parent);
    return m_employees.count();
}

QVariant EmployeeModel::data(const QModelIndex & index, int role) const {
    if (index.row() < 0 || index.row() >= m_employees.count())
        return QVariant();

    const Employee &employee = m_employees[index.row()];
    if (role == e_index)
        return employee.index();
    else if (role == NameRole)
        return employee.name();
    else if (role == averageRole)
        return employee.average();
    else if (role == assem)
        return employee.assem();
    else if (role == cplus)
        return employee.c_plus();
    else if (role == js)
        return employee.js();
    else if (role == qml)
        return employee.qml();
    else if (role == openGL)
        return employee.openGL();

    return QVariant();
}

QVariantMap EmployeeModel::get(int row) const
{
    QHash<int, QByteArray> names = roleNames();
    QHashIterator<int, QByteArray> i(names);
    QVariantMap res;
    QModelIndex idx = index(row, 0);
    while(i.hasNext()) {
        i.next();
        QVariant data = idx.data(i.key());
        res[i.value()] = data;
    }

    //        qDebug() << res;
    return res;
}

QHash<int, QByteArray> EmployeeModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[e_index] = "eindex";
    roles[NameRole] = "name";
    roles[averageRole] = "average";
    roles[assem] = "assem";
    roles[cplus] = "cplus";
    roles[js] = "js";
    roles[qml] = "qml";
    roles[openGL] = "opengl";
    return roles;
}
