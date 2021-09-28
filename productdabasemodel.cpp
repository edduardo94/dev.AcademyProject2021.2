#include "productdabasemodel.h"
#include <QQmlEngine>
#include <QCoreApplication>
#include <QSqlError>
#include <QSqlQuery>

const static QString TABLE_NAME = "produto";

ProductDabaseModel::ProductDabaseModel(QObject *parent, Database *db) : QSqlTableModel(parent, db->database()),
    m_db(db)
{
    setTable(TABLE_NAME);
    registerRoleColumns(Id, "id");
    registerRoleColumns(Name, "nome");
    registerRoleColumns(Type, "tipo");
    registerRoleColumns(Price, "preco");
    setEditStrategy(QSqlTableModel::OnRowChange);
    select();
}

QVariant ProductDabaseModel::data(const QModelIndex &index, int role) const
{
      if(m_roleColumns.contains(role)){
        int column = fieldIndex(m_roleColumns.value(role));
        QModelIndex item = QSqlTableModel::index(index.row(), column);
        QVariant result = QSqlTableModel::data(item);
        return result;
      }
      return QVariant();
}

QHash<int, QByteArray> ProductDabaseModel::roleNames() const
{
    return m_roleColumns;
}

void ProductDabaseModel::addProduct(QString name, QString type, double price)
{
    QSqlQuery query(m_db->database());
    query.prepare("INSERT INTO produto "
                  " (nome, tipo, preco) VALUES (:name, :type, :price)");
    query.bindValue(":name", name);
    query.bindValue(":type", type);
    query.bindValue(":price", price);
    bool success = query.exec();
    if(success){
        qDebug() << "INSERT BEM SUCEDIDO";
    } else {
        qDebug() << "INSERT MAL SUCEDIDO" << query.lastError();
    }
    select();
}

void ProductDabaseModel::removeProduct(QString id)
{
    QSqlQuery query(m_db->database());
    query.prepare("DELETE FROM produto WHERE id = :id");
    query.bindValue(":id", id);
    bool success = query.exec();
    if(success){
        qDebug() << "DELETE BEM SUCEDIDO";
    } else {
        qDebug() << "DELETE MAL SUCEDIDO" << query.lastError();
    }
    select();
}

void ProductDabaseModel::updateProduct(QString id, QString name, QString type, double price)
{
    QSqlQuery query(m_db->database());
    query.prepare("UPDATE produto SET "
                  " nome = :name, "
                  " tipo = :type,  "
                  " preco = :price  "
                  " WHERE id = :id");
    query.bindValue(":id", id);
    query.bindValue(":name", name);
    query.bindValue(":type", type);
    query.bindValue(":price", price);
    bool success = query.exec();
    if(success){
        qDebug() << "UPDATE BEM SUCEDIDO";
    } else {
        qDebug() << "UPDATE MAL SUCEDIDO" << query.lastError();
    }
    select();
}

void ProductDabaseModel::registerRoleColumns(int role, QByteArray columnName)
{
    m_roleColumns.insert(role, columnName);
}

void registerTypes() {
    qmlRegisterType<ProductDabaseModel>("Models", 1, 0, "ProductsDatabaseModel");
}

Q_COREAPP_STARTUP_FUNCTION(registerTypes)
