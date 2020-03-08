import QtQuick 2.14
import QtQuick.Controls 2.14

import OctaveSettingsEntry 1.0

Rectangle {
    id: root

    readonly property real elementWidth: width * 0.95
    readonly property real elementHeight: width * 0.16

    OctaveSettingsEntry {
        id: octaveSettings
        algorithm: algorithmField.text
        color: colorField.text
    }

    color: "transparent"
    border.color: "#20000000"
    border.width: width * 0.003

    height: elementHeight * 4 + settingsColumn.spacing

    Column {
        id: settingsColumn

        anchors.fill: root
        anchors.margins: (root.width - elementWidth) / 2
        spacing: root.width * 0.02

        TextField {
            id: colorField
            placeholderText: qsTr("Color")

            width: elementWidth
            height: elementHeight

            background: Item {}

            Rectangle {
                height: elementHeight * 0.5
                width: height
                anchors.right: colorField.right
                anchors.verticalCenter: colorField.verticalCenter
                color: "red"

                visible: !octaveSettings.isColorValid
            }
        }

        TextArea {
            id: algorithmField
            placeholderText: qsTr("Algorithm")

            width: elementWidth
            height: elementHeight * 3

            background: Item {}
        }
    }
}
