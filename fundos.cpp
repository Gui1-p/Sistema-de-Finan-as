#include "fundos.h"

//Fundos::Fundos() {}
Fundos::Fundos(string Nome, Data Abertura, double ValorAplicado, size_t Id) :
    m_Nome(Nome), m_Abertura(Abertura), m_ValorAplicado(ValorAplicado), m_Id(Id) {};




Poupanca::Poupanca(string Nome, Data Abertura, double ValorAplicado, float Rentabilidade, size_t Id) :
    Fundos(Nome, Abertura, ValorAplicado, Id), m_Rentabilidade(Rentabilidade) {};



Investimento::Investimento(string Nome, Data Abertura, double ValorAplicado, float Rentabilidade, Data Termino, size_t Id) :
    Poupanca(Nome, Abertura, ValorAplicado, Id, Rentabilidade), m_Termino(Termino) {};



CartaoCredito::CartaoCredito(string Nome, Data Abertura, double ValorAplicado, Data Fechamento, Data Fatura, size_t Id) :
    Fundos(Nome, Abertura, ValorAplicado, Id), m_Fechamento(Fechamento), m_Fatura(Fatura) {};