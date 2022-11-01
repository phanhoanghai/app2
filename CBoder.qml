import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Controls.Material 2.4
import QtQuick.Layouts 1.11
import QtQuick.Window 2.11

Item {
    anchors.fill: parent
    id: nulo

    Canvas {
        id: canvas
        width: 300
        height: 300
        property int maxX: 0
        property int maxY: 0
        property var coords: getCoords()

        function getCoords() {
            var retval = [];
            for(var i = 0;i < 10;i ++) {
                var x = Math.round(Math.random() * 1000);
                var y = Math.round(Math.random() * 1000);
                retval.push(x);
                retval.push(y);
            }
            return retval;
        }

        onPaint: {
            var context = canvas.getContext("2d");
            context.fillStyle = "white";
            context.fillRect(0,0,canvas.width,canvas.height);
            context.moveTo(canvas.width / 2, canvas.height / 2);
            context.strokeStyle = Qt.rgba(0,0,255,0.5);
            context.lineWidth = 5;
            context.beginPath();
            for(var i = 0;i < coords.length;i += 2) {
                context.lineTo(coords[i],coords[i + 1]);
                if(coords[i] > maxX) maxX = coords[i];
                if(coords[i + 1] > maxY) maxY = coords[i + 1];
            }
            context.closePath();
            context.stroke();
        }

        onPainted: {
            if(canvas.width < maxX || canvas.height < maxY) {
                canvas.width = maxX;
                canvas.height = maxY;
                update();
            }
        }
    }
}
