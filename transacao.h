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
public:
    Transacao(string Nome, string Detalhes, string Categoria, Data Data, TipoTransacao Tipo, FormaPagamento FormaPagamento, float Valor);

    string GetNome() const;
    string GetDetalhes() const;
    string GetCategoria() const;
    Data GetData() const;
    TipoTransacao GetTipoTransacao() const;
    FormaPagamento GetFormaPagamento() const;
    float GetValor() const;


    void SetNome(string Nome);
    void SetDetalhes(string Detalhes);
    void SetCategoria(string Categoria);
    void SetData(Data Data);
    void SetTipoTransacao(TipoTransacao Tipo);
    void SetFormaPagamento(FormaPagamento FormaPagamento);
    void SetValor(float Valor);
};

#endif // TRANSACAO_H
