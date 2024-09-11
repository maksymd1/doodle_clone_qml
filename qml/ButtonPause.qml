import QtQuick 2.0

Item {
    id : root
    property alias theWidth: root.width
    property alias theHeight: root.height
    property int thePointSize: 20
    signal buttonInMWclicked

    Image {
        id: background
        width: theWidth
        height: theHeight
        source: "qrc:///content/data/pause_button.png"
    }

    MouseArea {
        id : mouseItem
        anchors.fill: root
        hoverEnabled: true
        onPressed: { root.scale = 0.95 }
        onReleased: { root.scale = 1.0 }
        onClicked: { buttonInMWclicked()  }
//        onHoveredChanged: {

//        }
    }

    FontLoader {
        id: localFont;
        source: "qrc:///content/data/al-seana.ttf"
    }

    function open() { visible = true }
    function close() { visible = false }
}
