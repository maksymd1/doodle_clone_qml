import QtQuick 2.0

Item {
    id : root
    property alias theWidth: root.width
    property alias theHeight: root.height
    property alias text : textItem.text
    property int thePointSize: 20
    signal buttonInMWclicked

    Image {
        id: background

        width: theWidth
        height: theHeight
        source: "qrc:///content/data/button_bg.png"
    }

    MouseArea {
        id : mouseItem
        anchors.fill: root
        hoverEnabled: true
        onPressed: { root.scale = 0.95 }
        onReleased: { root.scale = 1.0 }
        onClicked: { buttonInMWclicked()  }
        onHoveredChanged: {
            if (mouseItem.containsMouse == true) {
                background.source = "qrc:///content/data/button_bg2.png"
            } else {
                background.source = "qrc:///content/data/button_bg.png"
            }
        }
    }

    FontLoader {
        id: localFont;
        source: "qrc:///content/data/al-seana.ttf"
    }

    Text {
        id: textItem
        anchors.centerIn: root
        font.pointSize: thePointSize
        font.bold : true
        font.family: localFont.name
        color : "black"

    }

    function open() { visible = true }
    function close() { visible = false }
}
