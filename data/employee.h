#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QString>

class Employee
{
public:
    Employee() = default;
    Employee(const int index, const QString& name,
             const float average, const int assem,
             const int c_plus, const int js,
             const int qml, const int openGL);

public:
    int index() const;
    QString name() const;
    float average() const;
    int assem() const;
    int c_plus() const;
    int js() const;
    int qml() const;
    int openGL() const;

private:
    int m_index;
    QString m_name;
    float m_average;
    int m_assem;
    int m_c_plus;
    int m_js;
    int m_qml;
    int m_openGL;
};

#endif // EMPLOYEE_H
