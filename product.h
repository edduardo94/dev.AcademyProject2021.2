#ifndef PRODUCT_H
#define PRODUCT_H

#include <QObject>

class Product
{    
public:
    explicit Product(QString nome, QString tipo, double preco);

    QString nome() const;
    QString tipo() const;
    double preco() const;

signals:

private:
    QString m_nome;
    QString m_tipo;
    double m_preco;

};

#endif // PRODUCT_H
