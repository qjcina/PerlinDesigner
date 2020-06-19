import QtQuick 2.14

Rectangle {
    id: root

    property alias text: buttonText.text
    property bool isHovered: false
    property bool isPressed: false

    signal clicked

    property color baseColor: "#FAFAFA"

    color: isPressed ? Qt.darker(baseColor, 1.3) : isHovered ? Qt.darker(baseColor, 1.2) : baseColor

    Behavior on color {
        ColorAnimation {
            duration: 85
        }
    }

    border.color: Qt.darker(color)
    border.width: width * 0.01

    Text {
        id: buttonText

        anchors.fill: root

        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter

        elide: Text.ElideRight
    }

    MouseArea {
        anchors.fill: root
        hoverEnabled: true
        onClicked: root.clicked()
        onHoveredChanged: root.isHovered = containsMouse
        onPressed: root.isPressed = true
        onReleased: root.isPressed = false
    }
}
