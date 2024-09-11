import QtQuick 2.0

Item
{
    id: root
    signal startNewGame()
    signal quitGame()
    signal highScores()

    Column
    {
        id: buttonColumn
        spacing: 20
        anchors.horizontalCenter: root.horizontalCenter
        anchors.verticalCenter: root.verticalCenter

        ButtonCommon
        {
            id: button1
            theWidth: 240
            theHeight: 50
            text : "New game"
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
            text : "Highscores"
            onButtonInMWclicked:
            {
                highScores()
            }
        }

        ButtonCommon
        {
            id: button3
            theWidth: 240
            theHeight: 50
            text : "Quit"
            onButtonInMWclicked:
            {
                quitGame()
            }
        }
    }
}
