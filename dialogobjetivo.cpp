#include "dialogobjetivo.h"
#include "ui_dialogobjetivo.h"

DialogObjetivo::DialogObjetivo(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogObjetivo)
{
    ui->setupUi(this);
}

DialogObjetivo::~DialogObjetivo()
{
    delete ui;
}

Objetivo DialogObjetivo::CriarObjetivo()
{
    QDate d = ui->Data->date();
    return Objetivo(
        ui->Nome->text().toStdString(),
        Data(d.day(), d.month(), d.year()),
        ui->Descricao->toPlainText().toStdString(),
        ui->ValorAlvo->value(),
        ui->ValorAtual->value()
    );
}
