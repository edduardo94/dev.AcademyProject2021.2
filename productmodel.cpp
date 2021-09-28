#include "productmodel.h"
#include <QQmlEngine>
#include <QCoreApplication>

ProductModel::ProductModel(QObject *parent) : QAbstractListModel(parent)
{
    setupData();
}

QVariant ProductModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()){
        return QVariant();
    }

    switch (role) {
    case Name:
        return m_products[index.row()].nome();
    case Type:
        return m_products[index.row()].tipo();
    case Price:
        return m_products[index.row()].preco();
    default:
        return QVariant();
    }

}

int ProductModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_products.count();
}

void ProductModel::setupData()
{
    beginResetModel();
    m_products.append(Product("Arroz", "Cesta basica", 10));
    m_products.append(Product("Macarrão", "Cesta basica", 3));    
    endResetModel();
}

QString ProductModel::title()
{    
    return m_title;
}

void ProductModel::setTitle(QString title)
{    
    if(title == m_title){
        return;
    }

    m_title = title;
    emit titleChanged();
}

void ProductModel::addProduct(QString nome, QString tipo, double preco)
{    
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_products.append(Product(nome, tipo, preco));
    endInsertRows();
}

void ProductModel::removeProduct(int index)
{
    beginRemoveRows(QModelIndex(), index, index);
    m_products.removeAt(index);
    endRemoveRows();
}

QHash<int, QByteArray> ProductModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Name] = "name";
    roles[Type] = "type";
    roles[Price] = "price";
    return roles;
}

void registerType() {
    qmlRegisterType<ProductModel>("Models", 1, 0, "ProductsModel");
}

Q_COREAPP_STARTUP_FUNCTION(registerType)
