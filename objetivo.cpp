#include "objetivo.h"

Objetivo::Objetivo(string Nome, Data DataLimite, string Detalhes, double ValorAlvo, double ValorAtual) :
    m_Nome(Nome),  m_DataLimite(DataLimite),  m_Detalhes(Detalhes),  m_ValorAlvo(ValorAlvo),  m_ValorAtual(ValorAtual) {};

string Objetivo::GetNome() {return m_Nome;}
Data Objetivo::GetDataLimite() {return m_DataLimite;}
string Objetivo::GetDetalhes() {return m_Detalhes;}
double Objetivo::GetValorAlvo() {return m_ValorAlvo;}
double Objetivo::GetValorAtual() {return m_ValorAtual;}

void Objetivo::SetNome(string Nome) { m_Nome = Nome;}
void Objetivo::SetDataLimite(Data DataLimite) { m_DataLimite = DataLimite;}
void Objetivo::SetDetalhes(string Detalhes) { m_Detalhes = Detalhes;}
void Objetivo::SetValorAlvo(double ValorAlvo) { m_ValorAlvo = ValorAlvo;}
void Objetivo::SetValorAtual(double ValorAtual) { m_ValorAtual = ValorAtual;}