import QtQuick 2.0

Item
{
    id: root
    signal startNewGame()
    signal backToMenu()

    Image {
        id: background
        anchors.fill: root
        source: "qrc:///content/data/background0.png"
    }

    Text {
        id: scoreTitle
        anchors.top: root.top
        anchors.topMargin: 180
        anchors.horizontalCenter: root.horizontalCenter

        font.bold : true
        font.pointSize: 30
        font.family: localFont.name
        color : "black"
        text: "Your score"
    }

    Text {
        id: scoreText
        anchors.top: scoreTitle.bottom
        anchors.horizontalCenter: root.horizontalCenter
        anchors.margins: 10

        font.bold : true
        font.pointSize: 30
        font.family: localFont.name
        color : "black"
        text: Engine.gameScore
    }


    FontLoader {
        id: localFont;
        source: "qrc:///content/data/al-seana.ttf"
    }

    Column
    {
        id: buttonColumn
        spacing: 20
        anchors.horizontalCenter: root.horizontalCenter
        anchors.top: scoreText.bottom
        anchors.topMargin: 50

        ButtonCommon
        {
            id: button1
            theWidth: 240
            theHeight: 50
            text : "Try again"
            onButtonInMWclicked:
            {
                startNewGame()
            }
        }

        ButtonCommon
        {
            id: button2
            theWidth: 240
            theHeight: 50
            text : "Back to menu"
            onButtonInMWclicked:
            {
                backToMenu()
            }
        }

    }
}
