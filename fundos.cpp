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

string Fundos::Tipo(){return "Fundo";}

double Fundos::Saldo(vector<Transacao>& Transacoes)
{
    double total = m_ValorAplicado;
    for (Transacao& t : Transacoes) {
        if (t.GetFundId() != m_Id) continue;        //
        if (t.GetTipoTransacao() == TipoTransacao::Entrada)
            total += t.GetValor();
        else
            total -= t.GetValor();
    }
    return total;
}


//cpnstrutor
Poupanca::Poupanca(string Nome, Data Abertura, double ValorAplicado, float Rentabilidade, size_t Id) :
    Fundos(Nome, Abertura, ValorAplicado, Id), m_Rentabilidade(Rentabilidade) {};

//funções
float Poupanca::GetRentabilidade() {return m_Rentabilidade; }

string Poupanca::Tipo(){return "Poupanca";}

void Poupanca::SetRentabilidade(float Rentabilidade) {m_Rentabilidade = Rentabilidade; }

double Poupanca::Saldo(vector<Transacao>& Transacoes)
{
    double base = Fundos::Saldo(Transacoes); //se não colocar o fundos:: vira recursividade
    return base * (1.0 + m_Rentabilidade / 100.0);
}


//construtor
Investimento::Investimento(string Nome, Data Abertura, double ValorAplicado, float Rentabilidade, Data Termino, size_t Id) :
    Poupanca(Nome, Abertura, ValorAplicado, Rentabilidade, Id), m_Termino(Termino) {};

//funções
Data Investimento::GetTermino() {return m_Termino; }
void Investimento::SetTermino(Data Termino) {m_Termino = Termino; }

string Investimento::Tipo(){return "Investimento";}

//construtor
CartaoCredito::CartaoCredito(string Nome, Data Abertura, double ValorAplicado, Data Fechamento, Data Vencimento, size_t Id, double Limite) :
    Fundos(Nome, Abertura, ValorAplicado, Id), m_Fechamento(Fechamento), m_Vencimento(Vencimento), m_Limite(Limite) {};


//funções

Data CartaoCredito::GetFechamento() {return m_Fechamento; }
Data CartaoCredito::GetVencimento() {return m_Vencimento; }
double CartaoCredito::GetLimite() {return m_Limite; }

string CartaoCredito::Tipo(){return "Cartao de credito";}

double CartaoCredito::Fatura(vector<Transacao>& Transacoes) {return -Saldo(Transacoes);}//isso é para que a fatura não apareça negativa


double CartaoCredito::LimiteDisponivel(vector<Transacao>& Transacoes) { return m_Limite - Fatura(Transacoes); }
double CartaoCredito::PercentualLimiteUsado(vector<Transacao>& Transacoes)
{
    if (m_Limite <= 0) return 0;
    return (Fatura(Transacoes) / m_Limite) * 100.0;
}


void CartaoCredito::SetLimite(double Limite) {m_Limite = Limite;}