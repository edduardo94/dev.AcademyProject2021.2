#ifndef PRODUCTCONTROLLER_H
#define PRODUCTCONTROLLER_H

#include <QJSValue>
#include <QObject>
#include "productmodel.h"
class ProductController : public QObject
{
    Q_OBJECT
public:
    explicit ProductController(QObject *parent = nullptr);
    void setProductsModel(ProductModel *model);
signals:

public slots:
    void newProduct(QJSValue value);

private:
    ProductModel *m_model;
};

#endif // PRODUCTCONTROLLER_H
