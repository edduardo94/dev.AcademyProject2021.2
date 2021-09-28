import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Controls.Material.impl 2.12
import Models 1.0

Dialog {
    id: addProductPopup
    height: 300
    width: 190
    signal okClicked(var nome, var tipo, var preco, var id)
    standardButtons: Dialog.Cancel | Dialog.Ok
    property var nome: ""
    property var tipo: ""
    property var preco: ""
    property var id: ""
    property var titleText: "Adicionar produto"

    ColumnLayout {
        anchors.fill: parent
        spacing: 8
        Text{
            Layout.fillWidth: true
            text: titleText
            horizontalAlignment: Text.AlignHCenter
        }
        TextField {
            id: textName
            text: nome
            onTextChanged: {
                nome = text
            }
            Layout.maximumWidth: parent.width
            placeholderText: "Nome"
        }

        TextField {
            id: textType
            text: tipo
            onTextChanged: {
                tipo = text
            }
            Layout.maximumWidth: parent.width
            placeholderText: "Tipo"
        }

        TextField {
            id: textPrice
            Layout.maximumWidth: parent.width
            text: preco
            onTextChanged: {
                preco = text
            }
            placeholderText: "Preço"
            validator: RegExpValidator { regExp: /[0-9]*.[0-9]{2}/ }
        }
    }

    function clearFields(){
        nome = ""
        preco = ""
        tipo = ""
        id = ""
    }

    onAccepted: {
        okClicked(nome, tipo, preco, id)
        clearFields()
    }
    onRejected: {
        clearFields()
    }
}
