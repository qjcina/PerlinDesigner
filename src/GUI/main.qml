import QtQuick 2.14
import QtQuick.Window 2.14

import ImagePainter 1.0

Window {
    id: rootWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Perlin Designer")

    Rectangle {
        id: leftColumn
        width: rootWindow.width * 0.65
        height: rootWindow.height
        color: "gray"        

        ImagePainter {
            id: perlinPreview

            anchors.horizontalCenter: leftColumn.horizontalCenter
            anchors.top: leftColumn.top
            anchors.topMargin: height * 0.05

            width: leftColumn.width * 0.9
            height: width
        }
    }

    Rectangle {
        id: rightColumn

        width: rootWindow.width - leftColumn.width
        height: rootWindow.height

        color: "white"
        anchors.left: leftColumn.right

        ListView {
            id: octaves

            anchors.top: rightColumn.top
            anchors.left: rightColumn.left
            anchors.right: rightColumn.right
            anchors.bottom: octavesControls.top
            anchors.margins: rightColumn.width * 0.05

            model: OctavesModelInstance

            clip: true

            delegate: OctaveSettings {
                width: octaves.width

                isOctaveColorValid: r_ColorValid
            }
        }

        Row {
            id: octavesControls
            anchors.left: rightColumn.left
            anchors.right: rightColumn.right
            anchors.bottom: rightColumn.bottom
            anchors.margins: rightColumn.width * 0.05

            spacing: width * 0.05

            height: rightColumn.height * 0.05

            Button {
                text: "Add octave"
                width: octavesControls.width / 2 - octavesControls.spacing / 2
                height: octavesControls.height

                onClicked: {
                    OctavesModelInstance.addOctave();
                }
            }

            Button {
                text: "Remove octave"
                width: octavesControls.width / 2 - octavesControls.spacing / 2
                height: octavesControls.height

                onClicked: {
                    OctavesModelInstance.removeOctave();
                }
            }
        }


    }

}
