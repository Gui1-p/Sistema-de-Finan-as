#include "dialogtransacao.h"
#include "ui_dialogtransacao.h"

DialogTransacao::DialogTransacao(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogTransacao)
{
    ui->setupUi(this);

    ui->Data->setDate(QDate::currentDate());
    ui->EntradaSelect->setChecked(true);

    ui->Categoria->addItems({"Moradia","Alimentação","Transporte","Lazer","Saúde","Outros"});
    ui->FormaPagamento->addItems({"Dinheiro","Débito","Pix","Cartao","Transferencia"});
}

DialogTransacao::~DialogTransacao()
{
    delete ui;
}

void DialogTransacao::PreencherFundos(vector<Fundos*>& ListaFundos)
{
    ui->Fundo->clear();
    for (Fundos* f : ListaFundos)
        ui->Fundo->addItem(QString::fromStdString(f->GetNome()), (qulonglong) f->GetId());
    //casting pra um tipo melhor aceito pelo qt, é um int de 64 bits sem sinal
}

Transacao DialogTransacao::CriarTransacao()
{
    QDate d = ui->Data->date();

    TipoTransacao tipo = ui->EntradaSelect->isChecked() ? TipoTransacao::Entrada : TipoTransacao::Saida;

    return Transacao(
        ui->Nome->text().toStdString(),
        ui->Detalhes->toPlainText().toStdString(),
        ui->Categoria->currentText().toStdString(),
        Data(d.day(), d.month(), d.year()),
        tipo,
        static_cast<FormaPagamento>(ui->FormaPagamento->currentIndex()),
        (float) ui->Valor->value(),
        ui->Fundo->currentData().toULongLong() //o id sendo reconvertido para size_t
        );
}
