#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include "classes_auxiliares.h"

using namespace std;

class Pessoa
{
private:
    string m_Nome;
    Data m_Data_nascimento;


public:
    Pessoa(string Nome, Data Nascimento);

    string GetNome() const;
    Data GetNascimento() const;

};

#endif // PESSOA_H
