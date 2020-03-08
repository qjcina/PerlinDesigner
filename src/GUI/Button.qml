import QtQuick 2.14

Rectangle {
    id: root

    property alias text: buttonText.text

    signal clicked

    color: "#FAFAFA"
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
        onClicked: root.clicked()
    }
}
