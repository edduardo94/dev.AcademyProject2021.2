#include "productcontroller.h"
#include "qdebug.h"
ProductController::ProductController(QObject *parent) : QObject(parent)
{

}

void ProductController::newProduct(QJSValue value)
{
    QVariantMap params = value.toVariant().toMap();
    QString name = params.value("name").toString();
    QString type = params.value("type").toString();
    double price = params.value("price").toDouble();        
    m_model->addProduct(name, type, price);
}

void ProductController::setProductsModel(ProductModel *model)
{
    m_model = model;
}


