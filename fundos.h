#ifndef FUNDOS_H
#define FUNDOS_H

#include "classes_auxiliares.h"
#include "transacao.h"
#include <vector>

//////////////////FUNDOS/////////////////////////
class Fundos
{
protected:
    string m_Nome;
    Data m_Abertura;
    double m_ValorAplicado;
    size_t m_Id;

public:
    Fundos(string Nome, Data Abertura, double ValorAplicado, size_t Id);
    virtual ~Fundos() = default;

    string GetNome();
    Data GetAbertura();
    double GetValorAplicado();
    size_t GetId();

    virtual string Tipo();

    void SetNome(string Nome);
    void SetAbertura(Data Abertura);
    void SetValorAplicado(double ValorAplicado);

    virtual double Saldo(vector<Transacao>& Transacoes);
};



//////////////////POUPANÇA/////////////////////////////////////////////////////
class Poupanca : public Fundos
{
protected:
    float m_Rentabilidade;

public:
    Poupanca(string Nome, Data Abertura, double ValorAplicado, float Rentabilidade, size_t Id);

    float GetRentabilidade();

    string Tipo() override ;

    double Saldo(vector<Transacao>& Transacoes) override;

    void SetRentabilidade(float Rentabilidade);
};



//////////////////INVESTIMENTO/////////////////////////////////////////////////
class Investimento : public Poupanca
{
private:
    Data m_Termino;

public:
    Investimento(string Nome, Data Abertura, double ValorAplicado, float Rentabilidade, Data Termino, size_t Id);

    string Tipo() override ;

    Data GetTermino();
    void SetTermino(Data Termino);
};



//////////////////CARTÃO/////////////////////////////////////////////////////
class CartaoCredito : public Fundos
{
private:
    Data m_Fechamento;
    Data m_Vencimento;
    double m_Limite;

public:
    CartaoCredito(string Nome, Data Abertura, double ValorAplicado, Data Fechamento, Data Vencimento, size_t Id, double Limite);

    Data GetFechamento();
    Data GetVencimento();
    double GetLimite();

    string Tipo() override ;

    double Fatura(vector<Transacao>& Transacoes);
    double LimiteDisponivel(vector<Transacao>& Transacoes);
    double PercentualLimiteUsado(vector<Transacao>& Transacoes);

    void SetLimite(double Limite);



};


#endif // FUNDOS_H
