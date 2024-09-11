import QtQuick 2.0
import io.qt.doodle 1.0

Item {
    id: doodleObjects

    property alias xpos: doodleObjects.x
    property alias ypos: doodleObjects.y

    property alias widthUnit: doodleObjects.width
    property alias heightUnit: doodleObjects.height

    property alias imageUnit: unitSprite.source

    Image {
        id: unitSprite
        anchors.fill: parent
    }
}
