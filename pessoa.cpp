#include "pessoa.h"

Pessoa::Pessoa(string Nome, Data Nascimento) : m_Nome(Nome), m_Data_nascimento(Nascimento){}

string Pessoa::GetNome() const {return m_Nome;}
Data Pessoa::GetNascimento() const {return m_Data_nascimento;}