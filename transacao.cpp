#include "transacao.h"

Transacao::Transacao(string Nome, string Detalhes, string Categoria, Data Data, TipoTransacao Tipo, FormaPagamento FormaPagamento, float Valor) :
    m_Nome(Nome), m_Detalhes(Detalhes), m_Categoria(Categoria), m_Data(Data), m_Tipo(Tipo), m_FormaPagamento(FormaPagamento), m_Valor(Valor) {};


//Gets

string Transacao::GetNome() const {return m_Nome;};
string Transacao::GetDetalhes() const {return m_Detalhes;};
string Transacao::GetCategoria()const {return m_Categoria;};
Data Transacao::GetData() const {return m_Data;};
TipoTransacao Transacao::GetTipoTransacao() const {return m_Tipo;};
FormaPagamento Transacao::GetFormaPagamento() const {return m_FormaPagamento;};
float Transacao::GetValor() const {return m_Valor;};


//Sets

void Transacao::SetNome(string Nome) {m_Nome = Nome; }
void Transacao::SetDetalhes(string Detalhes) {m_Detalhes = Detalhes;}
void Transacao::SetCategoria(string Categoria) {m_Categoria = Categoria;}
void Transacao::SetData(Data Data) {m_Data = Data;}
void Transacao::SetTipoTransacao(TipoTransacao Tipo) {m_Tipo = Tipo;}
void Transacao::SetFormaPagamento(FormaPagamento FormaPagamento) {m_FormaPagamento = FormaPagamento;}
void Transacao::SetValor(float Valor) { m_Valor = Valor;}