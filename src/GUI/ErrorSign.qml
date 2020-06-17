import QtQuick 2.14


Text {
    property bool displaySign: false

    width: height
    anchors.right: parent.right
    anchors.verticalCenter: parent.verticalCenter
    color: "#990100"
    text: "!"
    fontSizeMode: Text.Fit

    opacity: displaySign ? 1.0 : 0.0
    visible: opacity != 0
}
