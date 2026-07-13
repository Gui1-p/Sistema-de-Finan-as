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


public:
    Pessoa(string Nome, Data Nascimento);

    string GetNome() const;
    Data GetNascimento() const;

};

#endif // PESSOA_H
