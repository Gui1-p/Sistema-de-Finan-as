#ifndef FUNDOS_H
#define FUNDOS_H

#include "classes_auxiliares.h"

class Fundos
{
protected:
    string m_nome;
    Data m_Abertura;
    double m_ValorAplicado;

public:
    Fundos(string Nome, Data Abertura, double ValorAplicado);

};

class Poupanca : Fundos
{
protected:
    float m_rentabilidade;

public:
    Poupanca();
};

class Investimento : Poupanca
{
private:


public:

};


#endif // FUNDOS_H
