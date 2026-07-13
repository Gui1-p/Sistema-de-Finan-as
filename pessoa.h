#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <vector>
#include "classes_auxiliares.h"
#include "fundos.h"
#include "transacao.h"
#include "objetivo.h"

using namespace std;

class Pessoa
{
private:
    string m_Nome;
    Data m_Data_nascimento;

    vector<Fundos*> m_Fundos;
    vector<Transacao> m_Transacoes;
    vector<Objetivo> m_Objetivos;

    size_t m_ProximoId = 1; //forma de organizar os fundos


public:
    Pessoa(string Nome, Data Nascimento);
    ~Pessoa();

    string GetNome();
    Data GetNascimento();

    void AdicionarFundo(Fundos *Fundo);

    size_t GerarId();

    void AdicionarTransacao(Transacao Transacao);
    void AdicionarObjetivo(Objetivo Objetivo);

    vector<Fundos*>& GetFundos();
    vector<Transacao>& GetTransacoes();
    vector<Objetivo>& GetObjetivos();

    Fundos* BuscarFundo(size_t Id);

    double SaldoTotal();
    double Entradas(size_t Mes, size_t Ano);
    double Saidas(size_t Mes, size_t Ano);


};

#endif // PESSOA_H
