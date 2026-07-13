#ifndef OBJETIVO_H
#define OBJETIVO_H

#include "classes_auxiliares.h"

class Objetivo
{
private:
    string m_Nome;
    Data m_DataLimite;
    string m_Detalhes;
    double m_ValorAlvo;
    double m_ValorAtual;



public:
    Objetivo(string Nome, Data DataLimite, string Detalhes, double ValorAlvo, double ValorAtual);
};

#endif // OBJETIVO_H
