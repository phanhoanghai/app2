#include "employee.h"

Employee::Employee(const int index, const QString& name,
                   const float average, const int assem,
                   const int c_plus, const int js,
                   const int qml, const int openGL)
     :m_index(index) ,m_name(name), m_average(average),
      m_assem(assem), m_c_plus(c_plus),
      m_js(js), m_qml(qml), m_openGL(openGL) {

}

int Employee::index() const {
    return m_index;
}

QString Employee::name() const {
    return m_name;
}

float Employee::average() const {
    return m_average;
}

int Employee::assem() const {
    return m_assem;
}

int Employee::c_plus() const {
    return m_c_plus;
}

int Employee::js() const {
    return m_js;
}

int Employee::qml() const {
    return m_qml;
}

int Employee::openGL() const {
    return m_openGL;
}
