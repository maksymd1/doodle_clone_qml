import QtQuick 2.0

Item
{
    id: root
    signal backToMenu()

    Image {
        id: background
        anchors.fill: root
        source: "qrc:///content/data/background0.png"
    }

    FontLoader {
        id: localFont;
        source: "qrc:///content/data/al-seana.ttf"
    }


    ListView {
        width: root.width
        height: root.height - 200
        anchors.top: root.top
        anchors.topMargin: 100

        spacing: 15
        model: Engine.highScoresList
        delegate: Text {
            anchors.horizontalCenter: parent.horizontalCenter
            font.bold : true
            font.pointSize: 20
            font.family: localFont.name
            color : "black"
            text: modelData
        }
    }


    ButtonCommon
    {
        id: button2
        theWidth: 240
        theHeight: 50

        anchors.horizontalCenter: root.horizontalCenter
        anchors.bottom: root.bottom
        anchors.bottomMargin: 40

        text : "Back to menu"
        onButtonInMWclicked:
        {
            backToMenu()
        }
    }
}
