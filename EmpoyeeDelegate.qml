import QtQuick 2.2
import QtQuick.Controls 2.4
import QtQuick.Controls.Material 2.4
import QtQuick.Layouts 1.11

ItemDelegate {
    id: root
    width: 300
    height: 30
    checkable: true

    Label {
        id: timeLabel
        font.pixelSize: Qt.application.font.pixelSize
        text: model.name
        x: 0
        Layout.leftMargin: 50
    }

    Label {
        id: dateLabel
        font.pixelSize: Qt.application.font.pixelSize
        /*
          3.14159265359 -> 3.1
        */
        text: model.average.toFixed(1)
        x: 260
        font.bold: true
        color: "#1787b7"
    }
}
