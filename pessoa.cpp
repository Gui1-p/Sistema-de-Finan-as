#include "pessoa.h"

Pessoa::Pessoa(string Nome, Data Nascimento) : m_Nome(Nome), m_Data_nascimento(Nascimento){}

Pessoa::~Pessoa()
{
    for (Fundos* f : m_Fundos)
        delete f;
}

string Pessoa::GetNome() {return m_Nome;}
Data Pessoa::GetNascimento() {return m_Data_nascimento;}

void Pessoa::AdicionarFundo(Fundos *Fundo){
    m_Fundos.push_back(Fundo);
}
