#include "dialogfundos.h"
#include "ui_dialogfundos.h"

DialogFundos::DialogFundos(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogFundos)
{
    ui->setupUi(this);

    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
}

DialogFundos::~DialogFundos()
{
    delete ui;


}

Fundos* DialogFundos::CriarFundo(size_t Id)
{
    QDate d = ui->Data_2->date();
    return new Poupanca(
        ui->Nome_2->text().toStdString(),
        Data(d.day(), d.month(), d.year()),
        ui->ValorAtual_2->value(),
        0.0f,
        Id
    );
}