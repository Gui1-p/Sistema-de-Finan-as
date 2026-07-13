#ifndef TRANSACAO_H
#define TRANSACAO_H

#include "classes_auxiliares.h"

enum class TipoTransacao {Entrada, Saida};
enum class FormaPagamento {Dinheiro, Debito, Pix, Cartao, Transferencia};

class Transacao
{
private:
    string m_Nome;
    string m_Detalhes;
    string m_Categoria;
    Data m_Data;
    TipoTransacao m_Tipo;
    FormaPagamento m_FormaPagamento;
    float m_Valor;
    size_t m_FundId;
public:
    Transacao(string Nome, string Detalhes, string Categoria, Data Data, TipoTransacao Tipo, FormaPagamento FormaPagamento, float Valor, size_t FundId);

    string GetNome();
    string GetDetalhes();
    string GetCategoria();
    Data GetData();
    TipoTransacao GetTipoTransacao();
    FormaPagamento GetFormaPagamento();
    float GetValor();
    size_t GetFundId();


    void SetNome(string Nome);
    void SetDetalhes(string Detalhes);
    void SetCategoria(string Categoria);
    void SetData(Data Data);
    void SetTipoTransacao(TipoTransacao Tipo);
    void SetFormaPagamento(FormaPagamento FormaPagamento);
    void SetValor(float Valor);
    void SetFundId(size_t FundId);
};

#endif // TRANSACAO_H
