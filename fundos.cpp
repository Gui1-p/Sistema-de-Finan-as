#include "fundos.h"

//construtor
Fundos::Fundos(string Nome, Data Abertura, double ValorAplicado, size_t Id) :
    m_Nome(Nome), m_Abertura(Abertura), m_ValorAplicado(ValorAplicado), m_Id(Id) {};

//funções
string Fundos::GetNome() {return m_Nome;}
Data Fundos::GetAbertura() {return m_Abertura;}
double Fundos::GetValorAplicado() {return m_ValorAplicado;}
size_t Fundos::GetId() {return m_Id;}

void Fundos::SetNome(string Nome) {m_Nome = Nome; }
void Fundos::SetAbertura(Data Abertura) {m_Abertura = Abertura; }
void Fundos::SetValorAplicado(double ValorAplicado) {m_ValorAplicado = ValorAplicado; }



//cpnstrutor
Poupanca::Poupanca(string Nome, Data Abertura, double ValorAplicado, float Rentabilidade, size_t Id) :
    Fundos(Nome, Abertura, ValorAplicado, Id), m_Rentabilidade(Rentabilidade) {};

//funções
float Poupanca::GetRentabilidade() {return m_Rentabilidade; }

void Poupanca::SetRentabilidade(float Rentabilidade) {m_Rentabilidade = Rentabilidade; }


//construtor
Investimento::Investimento(string Nome, Data Abertura, double ValorAplicado, float Rentabilidade, Data Termino, size_t Id) :
    Poupanca(Nome, Abertura, ValorAplicado, Rentabilidade, Id), m_Termino(Termino) {};

//funções
Data Investimento::GetTermino() {return m_Termino; }
void Investimento::SetTermino(Data Termino) {m_Termino = Termino; }

//construtor
CartaoCredito::CartaoCredito(string Nome, Data Abertura, double ValorAplicado, Data Fechamento, Data Vencimento, size_t Id, double Limite) :
    Fundos(Nome, Abertura, ValorAplicado, Id), m_Fechamento(Fechamento), m_Vencimento(Vencimento), m_Limite(Limite) {};


//funções

Data CartaoCredito::GetFechamento() {return m_Fechamento; }
Data CartaoCredito::GetVencimento() {return m_Vencimento; }
double CartaoCredito::GetLimite() {return m_Limite; }

double CartaoCredito::Fatura() {return -(m_ValorAplicado);}


void CartaoCredito::SetLimite(double Limite) {m_Limite = Limite;}