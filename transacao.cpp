#include "transacao.h"

Transacao::Transacao(string Nome, string Detalhes, string Categoria, Data Data, TipoTransacao Tipo, FormaPagamento FormaPagamento, float Valor, size_t FundId) :
    m_Nome(Nome), m_Detalhes(Detalhes), m_Categoria(Categoria), m_Data(Data), m_Tipo(Tipo), m_FormaPagamento(FormaPagamento), m_Valor(Valor), m_FundId(FundId) {};


//Gets

string Transacao::GetNome() {return m_Nome;}
string Transacao::GetDetalhes() {return m_Detalhes;}
string Transacao::GetCategoria() {return m_Categoria;}
Data Transacao::GetData()  {return m_Data;}
TipoTransacao Transacao::GetTipoTransacao() {return m_Tipo;}
FormaPagamento Transacao::GetFormaPagamento() {return m_FormaPagamento;}
float Transacao::GetValor() {return m_Valor;}
size_t Transacao::GetFundId() {return m_FundId;};

//Sets

void Transacao::SetNome(string Nome) {m_Nome = Nome; }
void Transacao::SetDetalhes(string Detalhes) {m_Detalhes = Detalhes;}
void Transacao::SetCategoria(string Categoria) {m_Categoria = Categoria;}
void Transacao::SetData(Data Data) {m_Data = Data;}
void Transacao::SetTipoTransacao(TipoTransacao Tipo) {m_Tipo = Tipo;}
void Transacao::SetFormaPagamento(FormaPagamento FormaPagamento) {m_FormaPagamento = FormaPagamento;}
void Transacao::SetValor(float Valor) { m_Valor = Valor;}
void Transacao::SetFundId(size_t FundId){ m_FundId = FundId;}