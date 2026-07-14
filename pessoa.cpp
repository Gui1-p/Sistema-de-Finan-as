#include "pessoa.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>

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

void Pessoa::Salvar()
{
    QFile arq("dados.txt");
    if (!arq.open(QIODevice::WriteOnly | QIODevice::Text)) return;

    QTextStream saida(&arq);
    saida.setRealNumberNotation(QTextStream::FixedNotation);
    saida.setRealNumberPrecision(2);

    //primeira linha é o proximo id
    saida << "PROXIMOID;" << (qulonglong) m_ProximoId << "\n"; //qulonglong é basicamente um size_t

    //linhas seguintes são os fundos
    for (Fundos* f : m_Fundos) {
        QString tipo = QString::fromStdString(f->Tipo());
        Data a = f->GetAbertura();

        saida << "FUNDO;" << tipo << ";"
            << QString::fromStdString(f->GetNome()) << ";"
            << (qulonglong) a.GetDia() << ";" << (qulonglong) a.GetMes() << ";" << (qulonglong) a.GetAno() << ";"
            << f->GetValorAplicado() << ";"
            << (qulonglong) f->GetId();

        //como todas as outras classes são filhas de fundos o fundos em si fica fora de if para que possa ser reaproveitado o codigo
        if (tipo == "Poupanca") {
            Poupanca* p = (Poupanca*) f;
            saida << ";" << p->GetRentabilidade();//popança adiciona apenas rentabilidade
        }
        else if (tipo == "Investimento") {
            Investimento* i = (Investimento*) f;
            Data t = i->GetTermino();
            saida << ";" << i->GetRentabilidade()//invesimento deve colocar o rentabilidade e a data de termino
                << ";" << (qulonglong) t.GetDia() << ";" << (qulonglong) t.GetMes() << ";" << (qulonglong) t.GetAno();
        }
        else if (tipo == "CartaoCredito") {//cartão de crédito adiciona fechamento, vencimento e limite
            CartaoCredito* cartao = (CartaoCredito*) f;
            Data fec = cartao->GetFechamento();
            Data ven = cartao->GetVencimento();
            saida << ";" << (qulonglong) fec.GetDia() << ";" << (qulonglong) fec.GetMes() << ";" << (qulonglong) fec.GetAno()
                << ";" << (qulonglong) ven.GetDia() << ";" << (qulonglong) ven.GetMes() << ";" << (qulonglong) ven.GetAno()
                << ";" << cartao->GetLimite();
        }
        saida << "\n";
    }

    //proximas linhas são transações
    for (Transacao& t : m_Transacoes) {
        Data d = t.GetData();
        saida << "TRANSACAO;"
            << QString::fromStdString(t.GetNome()) << ";"
            << QString::fromStdString(t.GetDetalhes()) << ";"
            << QString::fromStdString(t.GetCategoria()) << ";"
            << (qulonglong) d.GetDia() << ";" << (qulonglong) d.GetMes() << ";" << (qulonglong) d.GetAno() << ";"
            << (int) t.GetTipoTransacao() << ";"
            << (int) t.GetFormaPagamento() << ";"
            << t.GetValor() << ";"
            << (qulonglong) t.GetFundId() << "\n";
    }

    //por fim objetivos
    for (Objetivo& o : m_Objetivos) {
        Data d = o.GetDataLimite();
        saida << "OBJETIVO;"
            << QString::fromStdString(o.GetNome()) << ";"
            << (qulonglong) d.GetDia() << ";" << (qulonglong) d.GetMes() << ";" << (qulonglong) d.GetAno() << ";"
            << QString::fromStdString(o.GetDetalhes()) << ";"
            << o.GetValorAlvo() << ";"
            << o.GetValorAtual() << "\n";
    }

    arq.close();
}

bool Pessoa::Carregar()
{
    QFile arq("dados.txt");

    if(!arq.open(QIODevice::ReadOnly | QIODevice::Text)) return false; //o ::text serve para garantir que o /n do SO sera convertido para o /n padrao

    QTextStream leitor(&arq);//declara o objeto que se move pelo arquivo

    while(!leitor.atEnd()){
        QString linha = leitor.readLine(); //le a linha inteira
        if (linha.isEmpty()) continue;

        QStringList partes = linha.split(';');//separa os campos a cada ; virando um vector com o conteudo entre os ;

        if (partes[0] == "PROXIMOID" && partes.size() >= 2) {
            m_ProximoId = partes[1].toULongLong();
        }

        else if (partes[0] == "FUNDO" && partes.size() >= 8) {//compara se é um fundo e se o tamanho no txt esta batendo
            string nome = partes[2].toStdString();
            Data abertura(partes[3].toUInt(), partes[4].toUInt(), partes[5].toUInt());
            double valor = partes[6].toDouble();
            size_t id = partes[7].toULongLong();

            if (partes[1] == "Poupanca" && partes.size() >= 9) {
                m_Fundos.push_back(new Poupanca(nome, abertura, valor, partes[8].toFloat(), id));
            }
            else if (partes[1] == "Investimento" && partes.size() >= 12) {
                Data termino(partes[9].toUInt(), partes[10].toUInt(), partes[11].toUInt());
                m_Fundos.push_back(new Investimento(nome, abertura, valor, partes[8].toFloat(), termino, id));
            }
            else if (partes[1] == "CartaoCredito" && partes.size() >= 15) {
                Data fech(partes[8].toUInt(),  partes[9].toUInt(),  partes[10].toUInt());
                Data venc(partes[11].toUInt(), partes[12].toUInt(), partes[13].toUInt());
                m_Fundos.push_back(new CartaoCredito(nome, abertura, valor, fech, venc, id, partes[14].toDouble()));
            }
        }
        else if (partes[0] == "TRANSACAO" && partes.size() >= 11) {//compara se é transação e se esta com tamanho ok
            Data d(partes[4].toUInt(), partes[5].toUInt(), partes[6].toUInt());
            m_Transacoes.push_back(Transacao(
                partes[1].toStdString(), partes[2].toStdString(), partes[3].toStdString(), d,
                (TipoTransacao) partes[7].toInt(),
                (FormaPagamento) partes[8].toInt(),
                partes[9].toFloat(),
                partes[10].toULongLong()));
        }
        else if (partes[0] == "OBJETIVO" && partes.size() >= 8) {//compara se é objetivo e se o tamanho ta ok
            Data d(partes[2].toUInt(), partes[3].toUInt(), partes[4].toUInt());
            m_Objetivos.push_back(Objetivo(
                partes[1].toStdString(), d, partes[5].toStdString(),
                partes[6].toDouble(), partes[7].toDouble()));
        }
    }

    arq.close();
    return true;
}

CartaoCredito* Pessoa::AcharCartao()
{
    for (Fundos* f : m_Fundos)
        if (f->Tipo() == "CartaoCredito") return (CartaoCredito*) f;
    return nullptr;
}