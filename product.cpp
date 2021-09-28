#include "product.h"

Product::Product(QString nome, QString tipo, double preco) :
    m_nome(nome),
    m_tipo(tipo),
    m_preco(preco)
{        
}

QString Product::nome() const
{
    return m_nome;
}

QString Product::tipo() const
{
    return m_tipo;
}

double Product::preco() const
{
    return m_preco;
}

