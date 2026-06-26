#ifndef TRANSACAO_H
#define TRANSACAO_H

#include "classes_auxiliares.h"

class Transacao
{
private:
    string m_Nome;
    string m_Detalhes;
    string m_Categoria;
    Data m_Data;
    bool m_Tipo;// 0 == saída, 1 == entrada ---> talvez implementar como subclasse
    FormaPagamento m_forma;


public:
    Transacao();
};

#endif // TRANSACAO_H
