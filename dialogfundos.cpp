#include "dialogfundos.h"
#include "ui_dialogfundos.h"

DialogFundos::DialogFundos(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogFundos)
{
    ui->setupUi(this);

    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

    ui->TipoFundo->addItems({"Poupanca", "Investimento", "Cartao de credito"});
    ui->Data_2->setDate(QDate::currentDate());
}

DialogFundos::~DialogFundos()
{
    delete ui;


}

Fundos* DialogFundos::CriarFundo(size_t Id)
{
    QDate data = ui->Data_2->date();
    Data abertura(data.day(), data.month(), data.year());
    string nome = ui->Nome_2->text().remove(';').toStdString();   // remove(';') protege o arquivo
    double valor = ui->ValorAtual_2->value();
    float rent = (float) ui->Rentabilidade->value();

    switch (ui->TipoFundo->currentIndex()) {
    case 0:
        return new Poupanca(nome, abertura, valor, rent, Id);

    case 1: {
        QDate term = data.addYears(1);                          // término: 1 ano depois
        return new Investimento(nome, abertura, valor, rent, Data(term.day(), term.month(), term.year()), Id);
    }

    default: {
        QDate fec = data.addDays(5); //data de fechamento
        QDate ven = data.addDays(15);//data vencimento
        return new CartaoCredito(nome, abertura, 0.0,
            Data(fec.day(), fec.month(), fec.year()),
            Data(ven.day(), ven.month(), ven.year()),
            Id, ui->Limite->value());
    }
    }
    /*QDate d = ui->Data_2->date();
    return new Poupanca(
        ui->Nome_2->text().toStdString(),
        Data(d.day(), d.month(), d.year()),
        ui->ValorAtual_2->value(),
        0.0f,
        Id
    );*/
}