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

size_t Pessoa::GerarId(){return m_ProximoId++; }

void Pessoa::AdicionarTransacao(Transacao Transacao) {m_Transacoes.push_back(Transacao);}
void Pessoa::AdicionarObjetivo(Objetivo Objetivo) {m_Objetivos.push_back(Objetivo);}

//retornam os endereços dos vectors
vector<Fundos*>& Pessoa::GetFundos() {return m_Fundos; }
vector<Transacao>& Pessoa::GetTransacoes() {return m_Transacoes; }
vector<Objetivo>& Pessoa::GetObjetivos() {return m_Objetivos;}

Fundos* Pessoa::BuscarFundo(size_t Id){
    for(Fundos* fundo : m_Fundos){
        if(fundo->GetId() == Id) return fundo;
    }
    return nullptr;
}

double Pessoa::SaldoTotal(){
    double total = 0;
    for(Fundos* fundo: m_Fundos){
        total += fundo->Saldo(m_Transacoes);
    }
    return total;
}
double Pessoa::Entradas(size_t Mes, size_t Ano){
    double total = 0;
    for(Transacao& T: m_Transacoes){
        if(T.GetTipoTransacao() == TipoTransacao::Entrada){
            if(T.GetData().GetAno() == Ano && T.GetData().GetMes() == Mes){
                total += T.GetValor();
            }
        }
    }
    return total;
}
double Pessoa::Saidas(size_t Mes, size_t Ano){
    double total = 0;
    for(Transacao& T: m_Transacoes){
        if(T.GetTipoTransacao() == TipoTransacao::Saida){
            if(T.GetData().GetAno() == Ano && T.GetData().GetMes() == Mes){
                total += T.GetValor();
            }
        }
    }
    return total;
}