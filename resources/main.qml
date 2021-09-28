import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Controls.Material.impl 2.12
import Models 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Caixa Dev.Academy")
    Material.accent: Material.Purple

    ListModel{
        id: carrinho
        function getPreco(){
            let total = 0;
            for(let i = 0; i < carrinho.rowCount(); i++){
                print(JSON.stringify(carrinho.get(i)))
                total += carrinho.get(i).preco * carrinho.get(i).quantidade
            }
            return total;
        }
    }

    AddProductPopup {
        id: addProductPopup
        anchors.centerIn: parent
        onOkClicked: {
            if(id === ""){
                print("produto")
                print(nome, tipo, preco)
                arrayDeProdutos.addProduct(nome, tipo, preco)
            } else {
                arrayDeProdutos.updateProduct(id, nome, tipo, preco)
            }
        }
    }

    ProductsDatabaseModel {
        id: arrayDeProdutos
    }

    Dialog{
        id: removeProductPopup
        anchors.centerIn: parent
        property var productIndex
        standardButtons: Dialog.Yes | Dialog.No
        Text{
            id: popupTitle
            text: "Deseja Remover o produto?"
        }
        onAccepted: {
            carrinho.remove(productIndex)
            total.text = carrinho.getPreco()
        }
    }

    Item {
        id: carrinhoId
        anchors{
            left: parent.left
            right: parent.right
            top: parent.top
        }
        height: parent.height/2.5
        RowLayout{
            width: parent.width
            id: productTitle
            Text{
                Layout.fillWidth: true
                text: "Carrinho"
                font.pixelSize: 15
                clip: true
            }

            Text{
                Layout.fillWidth: true
                id: total
                font.pixelSize: 15
                clip: true
                horizontalAlignment: Text.AlignRight
            }
        }

        ListaDeProdutos {
            width: parent.width
            produtoModel: carrinho
            buttonName: "Remover"
            showAddButton: false
            showQuantity: true
            clip: true
            anchors{
                topMargin: 10
                top: productTitle.bottom
                bottom: parent.bottom
            }
            onQuantityChanged: {
                total.text = carrinho.getPreco()
            }
            onRemoveClicked: {
                removeProductPopup.productIndex = index
                removeProductPopup.open()
            }
        }
    }

    Item{
        anchors{
            left: parent.left
            right: parent.right
            bottom: parent.bottom
            top: carrinhoId.bottom
        }
        RowLayout{
            width: parent.width
            clip: true
            id: title
            Text{
                id: titleText
                Layout.fillWidth: true
                text: "Lista de produtos"
                font.pixelSize: 15
                clip: true
            }

            Button{
                Layout.fillWidth: true
                text: "Adicionar produto"
                font.pixelSize: 15
                clip: true
                onClicked: {                    
                    addProductPopup.titleText = "Adicionar produto"
                    addProductPopup.open()
                }
            }
        }

        ListaDeProdutos {
            anchors{
                top: title.bottom
                bottom: parent.bottom
                margins: 10
            }
            clip: true
            width: parent.width
            produtoModel: arrayDeProdutos
            buttonName: "Colocar no carrinho"
            onEditClicked: function(product, index){
                addProductPopup.titleText = "Editar produto"
                addProductPopup.id = product.id
                addProductPopup.nome = product.nome
                addProductPopup.tipo = product.tipo
                addProductPopup.preco = product.preco
                addProductPopup.open()
            }
            onRemoveClicked: {
                arrayDeProdutos.removeProduct(id)
            }
            onAddClicked: {
                carrinho.append(product)
                total.text = carrinho.getPreco()
            }
        }
    }
}
