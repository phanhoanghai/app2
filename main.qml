import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Controls.Material 2.4
import QtQuick.Layouts 1.11
import QtQuick.Window 2.11
import com.myapp 1.0

ApplicationWindow {
    id: window
    width: 400
    height: 590
    visible: true
    property int currentIndex: 0

    QmlInterface {
        id: qmlInterface
    }

    ListModel {
        id: skillModel
        ListElement {
            name: "Assembly"
            icon: "../../resources/a.png"
        }
        ListElement {
            name: "C++"
            icon: "../../resources/c.png"
        }
        ListElement {
            name: "java Scripts"
            icon: "../../resources/j.png"
        }
        ListElement {
            name: "QML"
            icon: "../../resources/q.png"
        }
        ListElement {
            name: "OpenGL"
            icon: "../../resources/o.png"
        }
    }

    Pane {
        anchors.fill: parent
        focusPolicy: Qt.ClickFocus
    }

    Item {
        id: employeeInfo
        anchors.top: parent.top
        width: parent.width
        height: 230

        Label {
            id: employeeName
            anchors.horizontalCenter: parent.horizontalCenter
            y: 10
            color: "white"
            height: 30
            text: myModel.get(currentIndex).name
            anchors.horizontalCenterOffset: 0
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: Qt.application.font.pixelSize * 2
            font.bold: true
        }

        Item {
            id: listSkill
            anchors.top: employeeName.top
            anchors.topMargin: 50
            width: parent.width
            height: 260
            Column {
                anchors.horizontalCenter: parent.horizontalCenter
                Repeater{
                    model: skillModel
                    SkillInfo {
                        skillPoint: getSkillPoint(index)
                    }
                }
            }
        }
    }

    Item {
        id: actionItem
        width: 300
        height: 40
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: employeeInfo.bottom

        SearchBar {
            id: searchBar
            anchors.topMargin: 20
            anchors.left: parent.left
        }

        Button {
            id: refreshBtn
            text: "Refresh"
            width: 80
            height: 40
            anchors.left: searchBar.right
            anchors.leftMargin: 20

            onClicked: {
                console.log("request st")
                qmlInterface.test()
            }
        }
    }

    Item {
        id: listEmployeeInfo
        height: 350
        width: 300
        anchors.top: actionItem.bottom

        Item {
            id: listLabel
            anchors.top: parent.top
            width: parent.width
            height: 30
            anchors.horizontalCenter: parent.horizontalCenter
            Label {
                id: nameLabel
                font.pixelSize: Qt.application.font.pixelSize * 1.2
                text: "Name"
                x: 50
                font.bold: true
            }

            Label {
                id: averageLabel
                font.pixelSize: Qt.application.font.pixelSize * 1.2
                text: "Average"
                x: 280
                font.bold: true
            }
        }

        ListView {
            id: listEmployee
            anchors.top: listLabel.bottom
            x: 50
            width: parent.width
            height: 250
            clip: true
            ScrollBar.vertical: ScrollBar {
                active: true
            }
            model: myModel
            delegate: EmpoyeeDelegate {
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        listEmployee.currentIndex = index
                        currentIndex = index
                    }
                }
            }
            highlight: Rectangle
            {
                color:"#eab676"
                radius: 5
                opacity: 0.7
                focus: true
            }
        }
    }

    function getSkillPoint(index) {
        switch (index) {
        case 0 :
            return myModel.get(currentIndex).assem
            break
        case 1:
            return myModel.get(currentIndex).cplus
            break
        case 2:
            return myModel.get(currentIndex).js
            break
        case 3:
            return myModel.get(currentIndex).qml
            break
        case 4:
            return myModel.get(currentIndex).opengl
            break
        }
    }
}
