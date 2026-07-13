#include "objetivo.h"

Objetivo::Objetivo(string Nome, Data DataLimite, string Detalhes, double ValorAlvo, double ValorAtual) :
    m_Nome(Nome),  m_DataLimite(DataLimite),  m_Detalhes(Detalhes),  m_ValorAlvo(ValorAlvo),  m_ValorAtual(ValorAtual) {};