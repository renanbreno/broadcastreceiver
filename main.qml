import QtQuick 2.12
import QtQuick.Window 2.12
import QtQml.Models 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Window {
    width: 400
    height: 150
    visible: true
    title: qsTr("Broadcast Receiver")

    ColumnLayout {
        anchors.fill: parent
        RowLayout {
            Layout.alignment: Qt.AlignCenter
            Text {
                text: `Mensagem recebida: ${receiver.message}`
            }
        }
    }
}
