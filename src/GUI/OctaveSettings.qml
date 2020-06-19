import QtQuick 2.14
import QtQuick.Controls 2.14

import OctavesModel 1.0

Rectangle {
    id: root

    readonly property real elementWidth: width * 0.95
    readonly property real elementHeight: width * 0.16

    property bool isOctaveColorValid: true
    property bool isAlgorithmValid: true

    color: "transparent"
    border.color: "#20000000"
    border.width: width * 0.003

    height: colorField.height + algorithmField.height + buttonsRow.height + settingsColumn.spacing * 4

    function updateOctave()
    {
        OctavesModelInstance.setOctaveData(index, OctavesModel.Algorihm, algorithmField.text);
        OctavesModelInstance.setOctaveData(index, OctavesModel.Color, colorField.text);
    }

    Component.onCompleted: root.updateOctave()

    Column {
        id: settingsColumn

        anchors.fill: root
        anchors.margins: (root.width - elementWidth) / 2
        spacing: root.width * 0.02

        TextField {
            id: colorField
            text: "blue"

            width: elementWidth
            height: elementHeight

            background: ItemBackground {}

            ErrorSign {
                height: elementHeight * 0.5
                displaySign: !root.isOctaveColorValid
            }
        }

        TextArea {
            id: algorithmField

            width: elementWidth
            height: elementHeight * 2

            background: ItemBackground {}
            text: "x + y"

            ErrorSign {
                height: elementHeight * 0.5
                displaySign: !root.isAlgorithmValid
            }
        }

        Row {
            id: buttonsRow
            width: elementWidth
            height: elementHeight

            spacing: width / 15

            Button {
                text: "Delete"
                width: elementHeight * 2
                height: elementHeight * 0.8

                anchors.verticalCenter: buttonsRow.verticalCenter

                onClicked: {
                    OctavesModelInstance.removeOctave(index);
                }
            }

            Button {
                text: "Apply"
                width: elementHeight * 2
                height: elementHeight * 0.8

                anchors.verticalCenter: buttonsRow.verticalCenter

                onClicked: root.updateOctave()
            }
        }
    }
}
