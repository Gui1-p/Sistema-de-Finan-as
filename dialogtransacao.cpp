#include "dialogtransacao.h"
#include "ui_dialogtransacao.h"

DialogTransacao::DialogTransacao(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogTransacao)
{
    ui->setupUi(this);
}

DialogTransacao::~DialogTransacao()
{
    delete ui;
}
