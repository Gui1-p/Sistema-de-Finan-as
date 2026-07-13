#include "fundos.h"

//Fundos::Fundos() {}
Fundos::Fundos(string Nome, Data Abertura, double ValorAplicado) :
    m_Nome(Nome), m_Abertura(Abertura), m_ValorAplicado(ValorAplicado) {};





Poupanca::Poupanca(string Nome, Data Abertura, double ValorAplicado, float Rentabilidade) :
    Fundos(Nome, Abertura, ValorAplicado), m_Rentabilidade(Rentabilidade) {};



Investimento::Investimento(string Nome, Data Abertura, double ValorAplicado, float Rentabilidade, Data Termino) :
    Poupanca(Nome, Abertura, ValorAplicado, Rentabilidade), m_Termino(Termino) {};



CartaoCredito::CartaoCredito(string Nome, Data Abertura, double ValorAplicado, Data Fechamento, Data Fatura) :
    Fundos(Nome, Abertura, ValorAplicado), m_Fechamento(Fechamento), m_Fatura(Fatura) {};