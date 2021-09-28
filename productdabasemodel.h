#ifndef PRODUCTDABASEMODEL_H
#define PRODUCTDABASEMODEL_H

#include "database.h"

#include <QObject>
#include <QSqlTableModel>

class ProductDabaseModel : public QSqlTableModel
{
    Q_OBJECT
public:
    explicit ProductDabaseModel(QObject *parent = nullptr, Database *db = new Database());

    enum ProductRoles{
      Id = Qt::DisplayRole,
      Name,
      Type,
      Price
    };

   Q_INVOKABLE QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
   Q_INVOKABLE QHash<int, QByteArray> roleNames() const override;
   Q_INVOKABLE void addProduct(QString name, QString type, double price);
   Q_INVOKABLE void removeProduct(QString id);
   Q_INVOKABLE void updateProduct(QString id, QString name, QString type, double price);

private:
    void registerRoleColumns(int role, QByteArray columnName);
    QHash<int, QByteArray> m_roleColumns;
    Database *m_db = new Database();
};

#endif // PRODUCTDABASEMODEL_H
