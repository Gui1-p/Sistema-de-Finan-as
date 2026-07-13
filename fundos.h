#ifndef FUNDOS_H
#define FUNDOS_H

#include "classes_auxiliares.h"


//////////////////FUNDOS/////////////////////////
class Fundos
{
protected:
    string m_Nome;
    Data m_Abertura;
    double m_ValorAplicado;

public:
    Fundos(string Nome, Data Abertura, double ValorAplicado);
    virtual ~Fundos();

};



//////////////////POUPANÇA/////////////////////////////////////////////////////
class Poupanca : public Fundos
{
protected:
    float m_Rentabilidade;

public:
    Poupanca(string Nome, Data Abertura, double ValorAplicado, float Rentabilidade);
};



//////////////////INVESTIMENTO/////////////////////////////////////////////////
class Investimento : public Poupanca
{
private:
    Data m_Termino;

public:
    Investimento(string Nome, Data Abertura, double ValorAplicado, float Rentabilidade, Data Termino);

};



//////////////////CARTÃO/////////////////////////////////////////////////////
class CartaoCredito : public Fundos
{
private:
    Data m_Fechamento;
    Data m_Fatura;

public:
    CartaoCredito(string Nome, Data Abertura, double ValorAplicado, Data Fechamento, Data Fatura);


};


#endif // FUNDOS_H
