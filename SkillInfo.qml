import QtQuick 2.12
import QtQuick.Controls 2.12
import QtGraphicalEffects 1.0

Item {
    property int skillPoint: 0
    width: 300
    height: 30

    Image {
        id: skillIcon
        width: 15
        height: 15
        x: 10
        source: model.icon
        anchors.verticalCenter: parent.verticalCenter
        smooth: true
        visible: false
    }

    ColorOverlay {
        anchors.fill: skillIcon
        source: skillIcon
        color: "#d3d0cf"
    }

    Text {
        id: skillName
        font.pixelSize: Qt.application.font.pixelSize * 1.2
        text: model.name
        x: 50
        color: "#d3d0cf"
        anchors.verticalCenter: parent.verticalCenter
    }

    Text {
        id: textSkillPoint
        font.pixelSize: Qt.application.font.pixelSize * 1.2
        text: skillPoint + "/5"
        x: 200
        color: "#d3d0cf"
        anchors.verticalCenter: parent.verticalCenter
    }

    Image {
        id: result
        width: 15
        height: 15
        x: 270
        source: skillPoint >= 3 ?  "../../resources/check.png"
                               : "../../resources/cross.png"
        anchors.verticalCenter: parent.verticalCenter
        smooth: true
        visible: false
    }

    ColorOverlay {
        anchors.fill: result
        source: result
        color: skillPoint >= 3 ? "#1e81b0" : "#ff0000"
    }
}
