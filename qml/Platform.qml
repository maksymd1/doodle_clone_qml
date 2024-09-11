import QtQuick 2.0

Item {
    id: doodleObjects
    x: modelData.objectRect.x
    y: modelData.objectRect.y
    width: modelData.objectRect.width
    height: modelData.objectRect.height


    Image {
        anchors.fill: parent
        source: modelData.imagePath
    }
}
