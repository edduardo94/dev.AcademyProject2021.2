#ifndef PRODUCTMODEL_H
#define PRODUCTMODEL_H

#include "product.h"

#include <QAbstractListModel>
#include <QList>

class ProductModel : public QAbstractListModel
{
    Q_OBJECT
public:

    enum ProductRoles{
      Name = Qt::DisplayRole,
      Type,
      Price
    };

    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)

    ProductModel(QObject *parent = nullptr);
    QVariant data(const QModelIndex &index, int role) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    void setupData();
    QString title();
    Q_INVOKABLE void setTitle(QString title);

public slots:
    void addProduct(QString nome, QString tipo, double preco);
    void removeProduct(int index);

signals:
    void titleChanged();

private:
    QHash<int, QByteArray> roleNames() const override;
    QList<Product> m_products;
    QString m_title;
};

#endif // PRODUCTMODEL_H
