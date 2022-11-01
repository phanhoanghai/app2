import QtQuick 2.12
import QtQuick.Controls 2.12

TextField {
    id: textField
    width: 40
    implicitHeight: 40

    property color colorDefault: "#ffffff"
    property color colorOnfocus: "#202225"
    property color colorMouseOver: "#2B2f38"
    property color colorBorderOnFocus: "#ff007f"
    property color colorDarkTheme: "#303030"

    placeholderText: qsTr("Filter by name")
    color: "#372b25"
    font.family: "Segoe UI"
    font.pointSize: 10
    clip: true
    leftPadding: 42
    rightPadding: 35
    selectByMouse: true
    selectionColor: colorBorderOnFocus
    placeholderTextColor: "#000000"

    background: Rectangle {
        Rectangle {
            anchors.fill: parent
            id: bgColor
            color: colorDefault
            radius: 8
            border.color: colorDefault
            border.width: 2

            Image {
                id: iconSearch
                x: 7
                y: 7
                source: "../../resources/icon-search.png"
                anchors.leftMargin: 10
                fillMode: Image.PreserveAspectFit
                sourceSize.height: 20
                opacity: 0.5
                width: 25
                height: 25
            }
        }
    }

    onFocusChanged: {
        if (textField.focus) {
            textOnFocus.running = true
             textField.placeholderText = "Filter by name"
        } else {
            if (!textField.displayText) {
            textLostFocus.running = true
            textField.placeholderText = ""
            }
        }
    }

    PropertyAnimation {
        id: textOnFocus
        target: textField
        properties: "width"
        to: 200
        duration: 300
        easing.type: Easing.OutQuint
    }

    PropertyAnimation {
        id: textLostFocus
        target: textField
        properties: "width"
        to: 40
        duration: 500
        easing.type: Easing.OutQuint
    }
}
