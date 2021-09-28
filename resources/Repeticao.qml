import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.3

ColumnLayout{
    width: parent.width
    height: parent.height
    property alias repeaterAlias: repeaterId
    Repeater{        
        id: repeaterId
        Text{
            text: `nome: ${modelData.nome}, idade: ${modelData.idade}`
            font.pixelSize: 26
        }
    }
}
