import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.12

ListView {
    id: root
    property alias produtoModel: root.model
    property var buttonName: ""
    property bool showAddButton: true
    signal addClicked(var product, var index)
    signal removeClicked(var id, var index)
    signal editClicked(var product, var index)
    signal quantityChanged()
    property bool showQuantity: false
    spacing: 3
    delegate: Item {
        height: 50
        width: parent.width        
        Card{
            RowLayout{
                anchors.fill: parent
                clip: true
                spacing: 3
                Text {
                    Layout.alignment: Qt.AlignHCenter
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.preferredWidth: 40
                    font.pixelSize: 15
                    Layout.leftMargin: 5
                    text: model.nome
                    wrapMode: Text.WordWrap
                    verticalAlignment: Text.AlignVCenter
                }

                Text {
                    Layout.alignment: Qt.AlignHCenter
                    Layout.preferredWidth: 40
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    font.pixelSize: 15
                    text: model.tipo
                    verticalAlignment: Text.AlignVCenter
                }

                Text {
                    Layout.preferredWidth: 40
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    font.pixelSize: 15
                    text: model.preco
                    horizontalAlignment: Text.AlignRight
                    Layout.rightMargin: 20
                    verticalAlignment: Text.AlignVCenter
                }

                RowLayout {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.preferredWidth: 60
                    visible: showQuantity
                    Button{
                        Layout.alignment: Qt.AlignHCenter
                        Layout.minimumWidth: 25
                        Layout.fillHeight: true
                        Layout.rightMargin: 5
                        text: "+"
                        onClicked: {
                            model.quantidade = quantidade + 1
                            quantityChanged()
                        }
                    }

                    Text{
                        text: model.quantidade
                        font.pixelSize: 15
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                        Layout.minimumWidth: 10
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                    }

                    Button{
                        Layout.alignment: Qt.AlignHCenter
                        Layout.minimumWidth: 25
                        Layout.fillHeight: true
                        Layout.rightMargin: 5
                        text: "-"
                        onClicked: {

                            if(quantidade - 1 === 0){
                                removeClicked(model.id, index)
                            } else {
                                model.quantidade = quantidade - 1
                            }
                            quantityChanged()
                        }
                    }

                }

                Button{
                    id: addButton
                    Layout.alignment: Qt.AlignHCenter
                    visible: showAddButton
                    Layout.minimumWidth: 25
                    Layout.fillHeight: true
                    Layout.rightMargin: 5                    
                    icon.source: "qrc:/shopping-cart.svg"
                    onClicked: {
                        addClicked({id: model.id, nome: model.nome, tipo: model.tipo, preco: model.preco, quantidade: 1}, index)
                    }
                }
                Button{
                    Layout.alignment: Qt.AlignHCenter
                    Layout.minimumWidth: 25
                    Layout.fillHeight: true
                    Layout.rightMargin: 5                    
                    visible: showAddButton
                    text: "Editar"
                    onClicked: {
                        editClicked({id: model.id, nome: model.nome, tipo: model.tipo, preco: model.preco}, index)
                    }
                }

                Button{
                    Layout.alignment: Qt.AlignHCenter
                    Layout.minimumWidth: 25
                    Layout.fillHeight: true
                    Layout.rightMargin: 5

                    icon.source: "qrc:/trash.svg"
                    onClicked: {
                        removeClicked(model.id, index)
                    }
                }
            }
        }
    }
}
