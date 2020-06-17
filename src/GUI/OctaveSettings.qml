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

            onEditingFinished: OctavesModelInstance.setOctaveData(index, OctavesModel.Color, text);

            background: ItemBackground {}

            ErrorSign {
                height: elementHeight * 0.5
                displaySign: !root.isOctaveColorValid
            }
        }

        TextArea {
            id: algorithmField
            placeholderText: qsTr("Algorithm")

            width: elementWidth
            height: elementHeight * 2

            onEditingFinished: OctavesModelInstance.setOctaveData(index, OctavesModel.Algorihm, text);

            background: ItemBackground {}
            text: "x + y"

            Component.onCompleted: onEditingFinished()

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
                text: "X"
                width: elementHeight
                height: elementHeight

                onClicked: {
                    OctavesModelInstance.removeOctave(index);
                }
            }
        }
    }
}
