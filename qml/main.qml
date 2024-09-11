import QtQuick 2.0
import io.qt.doodle 1.0

Item {
    id: root
    width: 400
    height: 700
    focus: true

    property int visiblePage
    /*
      StartingMenu = 0
      Doodle = 1

      HighscoreMenu = 2
      EndgameMenu = 3
      */

    Connections {
        target: Engine
        onSignalPlayerDead: {
            visiblePage = 3
        }
    }

    Image {
        id: background
        anchors.fill: root
        opacity: 100
        source: "qrc:///content/data/background0.png"
    }

    Item {
        id: rootpage0
        anchors.fill: parent
        visible: ( visiblePage === 0 )

        StartingMenu {
            id: menu
            anchors.fill: rootpage0
            onStartNewGame: {
                visiblePage = 1
                Engine.startNewGame()
            }
            onQuitGame: {
                Engine.quitGame()
            }
            onHighScores: {
                visiblePage = 2
            }
        }
    }

    Item {
        id: rootpage1
        anchors.fill: parent
        visible: ( visiblePage === 1 )

        DoodleUnit {
            id: unit
            xpos: doodleInfo.objectRect.x
            ypos: doodleInfo.objectRect.y
            widthUnit: doodleInfo.objectRect.width
            heightUnit: doodleInfo.objectRect.height
            imageUnit: doodleInfo.imagePath
        }

        Doodle {
            objectName: "player1Doodle"
            id: doodleInfo
            Component.onCompleted: {
                    Engine.addDoodleInstance(doodleInfo)
               }
        }

        Repeater
        {
            id: platformsRepeater
            model: Engine.doodlePlatforms
            Platform { }
        }

        Text {
            id: scoreText
            anchors.top: rootpage1.top
            anchors.right: rootpage1.right
            anchors.margins: 10

            font.bold : true
            font.pointSize: 25
            font.family: localFont.name
            color : "black"
            text: Engine.gameScore
        }

        ButtonPause {
            id: pauseButton
            theWidth: 40
            theHeight: 40
            anchors.top: rootpage1.top
            anchors.left: rootpage1.left
            anchors.margins: 10
            visible: true
            onButtonInMWclicked : {
                if(pauseButton.visible == true) {
                    if(Engine.timerRunning) {
                        Engine.stopTimer()
                        pauseBackground.visible = true
                    } else {
                        Engine.startTimer()
                        pauseBackground.visible = false
                    }
                }
            }
        }

        Item {
            id: pauseBackground
            width: rootpage1.width
            height: rootpage1.height
            visible: false

            Rectangle {
                anchors.fill: parent
                color: "orange"
                opacity: 0.2
            }
            Text {
                anchors.centerIn: parent
                font.bold : true
                font.pointSize: 25
                font.family: localFont.name
                color : "black"
                text: "PAUSED"
            }
        }
    }

    Item {
        id: rootpage2
        anchors.fill: parent
        visible: ( visiblePage === 2 )

        HighscoreMenu {
            id: highScoreMenu
            anchors.fill: rootpage2

            onBackToMenu: {
                visiblePage = 0
            }
        }
    }

    Item {
        id: rootpage3
        anchors.fill: parent
        visible: ( visiblePage === 3 )

        EndgameMenu {
            id: endgameMenu
            anchors.fill: rootpage3

            onStartNewGame: {
                menu.startNewGame()
                visiblePage = 1
            }
            onBackToMenu: {
                menu.visible = true
                visiblePage = 0
            }
        }
    }

    FontLoader {
        id: localFont;
        source: "qrc:///content/data/al-seana.ttf"
    }

    Keys.onPressed:
    {
        switch(event.key)
        {
        case Qt.Key_Space:

            break;
        case Qt.Key_Left:
            doodleInfo.setSpeedXA(-10)
            break;
        case Qt.Key_Right:
            doodleInfo.setSpeedXA(10)
            break;
        case Qt.Key_Up:

            break;
        case Qt.Key_Down:

            break;

        case Qt.Key_Escape:
            pauseButton.buttonInMWclicked()
        }
    }
    Keys.onReleased: {
        doodleInfo.setSpeedXA(0)
    }
}
