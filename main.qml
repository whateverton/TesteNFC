import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Test NFC")

    signal readSignal()
    signal cancelReadWrite()
    signal writeData(data: string)

    ScrollView {
        id: view
        visible: true
        TextArea{
            id: text
            text: "Type here to write in the tag"
        }
    }

    Row {
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 10
        Button {
            id: readButtom
            text: qsTr("Read")
            onClicked: readSignal()
        }
        Button {
            id: writeButtom
            text: qsTr("Write")
            onClicked: writeData(text.text)
        }
        Button {
            id: cancelButtom
            text: qsTr("Cancel")
            onClicked: cancelReadWrite()
        }
    }
}
