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

    string GetNome();
    Data GetDataLimite();
    string GetDetalhes();
    double GetValorAlvo();
    double GetValorAtual();

    void SetNome(string Nome);
    void SetDataLimite(Data DataLimite);
    void SetDetalhes(string Detalhes);
    void SetValorAlvo(double ValorAlvo);
    void SetValorAtual(double ValorAtual);
};

#endif // OBJETIVO_H
